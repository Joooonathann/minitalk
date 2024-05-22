/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:34:38 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/22 09:03:43 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

t_clients	*g_clients = NULL;

static char	*add_char(t_clients *client)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (client->len_message + 1));
	if (!result)
	{
		delete_all_clients(&g_clients);
		exit(1);
	}
	i = 0;
	while (i < client->len_message)
	{
		result[i] = client->message[i];
		i++;
	}
	result[i] = client->c;
	free(client->message);
	return (result);
}

static void	add_client(pid_t pid_client)
{
	t_clients	*tmp;
	t_clients	*new_client;

	new_client = malloc(sizeof(t_clients));
	if (!new_client)
	{
		delete_all_clients(&g_clients);
		exit(1);
	}
	new_client->pid = pid_client;
	new_client->message = NULL;
	new_client->c = 0;
	new_client->bits = 0;
	new_client->len_message = 0;
	new_client->next = NULL;
	if (g_clients == NULL)
		g_clients = new_client;
	else
	{
		tmp = g_clients;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_client;
	}
}

void	char_process(t_clients **client_handler)
{
	t_clients	*client;

	client = *client_handler;
	if (client->bits == 8)
	{
		client->message = add_char(client);
		if (!client->message)
		{
			delete_all_clients(&g_clients);
			exit(1);
		}
		client->bits = 0;
		client->c = 0;
		client->len_message++;
	}
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	t_clients	*client;

	(void) context;
	if (!exist_client(info->si_pid, &g_clients))
	{
		add_client(info->si_pid);
		usleep(250);
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	client = get_client(info->si_pid, &g_clients);
	if (sig == SIGUSR1)
		client->c |= (0x01 << client->bits);
	client->bits++;
	char_process(&client);
	if (client->message && client->message[client->len_message - 1] == '\0')
	{
		ft_printf("%d => %s\n", client->pid, client->message);
		kill(client->pid, SIGUSR2);
		delete_client(client, &g_clients);
	}
	else
		kill(client->pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID => %d\n", getpid());
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
