/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:47:04 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/22 09:05:27 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

t_info	g_info = {NULL, 0, 0, 0};

static void	send_sig(void)
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

static void	handler(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		send_sig();
	else
	{
		free(g_info.message);
		ft_printf("Message received !\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error: use ./client <pid> <message>\n");
		return (1);
	}
	if (!init_info((pid_t)ft_atoi(argv[1]), argv[2], &g_info))
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
