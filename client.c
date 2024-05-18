/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:47:48 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/18 21:20:22 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_info
{
	char	*message;
	pid_t	pid;
	int		bits;
	int		index;
}			t_info;

t_info	g_info = {NULL, 0};

int		is_valid_pid(pid_t pid)
{
	if (kill(pid, SIGUSR1) == 0)
		return (1);
	else
		return (0);
}

int	init_info(pid_t pid_server, char *message)
{
	if (is_valid_pid(pid_server))
		g_info.pid = pid_server;
	else
	{
		ft_printf("Error: the pid is incorrect\n");
		return (0);
	}
	if (message != NULL)
	{
		g_info.message = ft_strdup(message);
		if (!g_info.message)
		{
			ft_printf("Error: problem memory\n");
			return (0);
		}
	}
	else
	{
		ft_printf("Error: the message is incorrect\n");
		return (0);
	}
	g_info.bits = 0;
	g_info.index = 0;
	return (1);
}
void	handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
	{
		if (g_info.bits == 8)
		{
			g_info.bits = 0;
			g_info.index++;
		}
		if ((g_info.message[g_info.index] & (0x01 << g_info.bits)) != 0)
		{
			if (kill(g_info.pid, SIGUSR1) == -1)
			{
				free(g_info.message);
				exit(1);
			}
		}
		else
		{
			if (kill(g_info.pid, SIGUSR2) == -1)
			{
				free(g_info.message);
				exit(1);
			}
		}
		g_info.bits++;
	}
	else
	{
		free(g_info.message);
		ft_printf("Message reçu.\n");
		exit(0);
	}
}

int main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error: use ./client <pid> <message>\n");
		return (1);
	}
	if (!init_info((pid_t)ft_atoi(argv[1]), argv[2]))
		return (1);
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}