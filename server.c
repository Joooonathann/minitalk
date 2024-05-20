/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:20:35 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/20 09:11:50 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_clients
{
	pid_t				pid;
	char				*message;
	char				c;
	int					bits;
	int					len_message;
	struct s_clients	*next;
}						t_clients;


t_clients	*g_clients = NULL;

void	delete_all_clients(void)
{
	t_clients	*next;
	
	if (g_clients == NULL)
		return ;
	while (g_clients)
	{
		next = g_clients->next;
		if (g_clients->message)
			free(g_clients->message);
		free(g_clients);
		g_clients = next;
	}
	g_clients = NULL;
}

void	add_client(pid_t pid_client)
{
	t_clients	*tmp;
	t_clients	*new_client;

	new_client = malloc(sizeof(t_clients));
	if (!new_client)
	{
		delete_all_clients();
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

int	exist_client(pid_t pid_client)
{
	t_clients	*clients;

	clients = g_clients;
	while (clients)
	{
		if (clients->pid == pid_client)
			return (1);
		clients = clients->next;
	}
	return (0);
}
char	*add_char(t_clients *client)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (client->len_message + 1));
	if (!result)
	{
		delete_all_clients();
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
void delete_client(t_clients *client)
{
	t_clients *current;
	t_clients *previous;

	current = g_clients;
	previous = NULL;
	while (current && current != client)
	{
		previous = current;
		current = current->next;
	}
	if (!current)
		return;
	if (previous == NULL)
		g_clients = current->next;
	else
		previous->next = current->next;
	if (current->message)
		free(current->message);
	free(current);
}

int	verif_clients(t_clients *client_current)
{
	t_clients *clients;
	int		is_client;

	is_client = 0;
	clients = g_clients;
	if (!clients)
		return (0);
	while (clients)
	{
		if (kill(clients->pid, SIGUSR2) == -1)
		{
			if (clients == client_current)
				is_client = 1;
			delete_client(clients);
		}
		clients = clients->next;
	}
	if (is_client)
		return (1);
	return (0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	t_clients	*client;

	if (!exist_client(info->si_pid))
	{
		add_client(info->si_pid);
		if (kill(info->si_pid, SIGUSR1) == -1)
		{
			ft_printf("Lost contact with client: %d\n", client->pid);
			delete_client(client);
		}
		return ;
	}
	client = g_clients;
	while (client->pid != info->si_pid)
		client = client->next;
	if (verif_clients(client))
		return ;
	if (sig == SIGUSR1)
		client->c |= (0x01 << client->bits);
	client->bits++;
	if (client->bits == 8)
	{
		client->message = add_char(client);
		if (!client->message)
		{
			delete_all_clients();
			exit(1);
		}
		client->bits = 0;
		client->c = 0;
		client->len_message++;
	}
	if (client->message && client->message[client->len_message - 1] == '\0')
	{
		ft_printf("%d => %s\n", client->pid, client->message);
		if (kill(client->pid, SIGUSR2) == -1)
			ft_printf("Lost contact with client: %d\n", client->pid);
		delete_client(client);
	}
	else
	{
		if (kill(client->pid, SIGUSR1) == -1)
		{
			ft_printf("Lost contact with client: %d\n", client->pid);
			delete_client(client);
		}
	}
}

int	main(void)
{
	struct sigaction sa;

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