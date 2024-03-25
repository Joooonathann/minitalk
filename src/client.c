/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:55:46 by jalbiser          #+#    #+#             */
/*   Updated: 2024/03/22 09:47:47 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

int	send_bit(char c, int pid)
{
	int	bin;

	bin = 0;
	while (bin < 8)
	{
		if ((c & (0x01 << bin)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		usleep(1000);
		bin++;
	}
	return (1);
}

int	send_message(const char *str, int pid)
{
	while (*str)
	{
		if (!send_bit(*str, pid))
			return (0);
		str++;
	}
	send_bit('\n', pid);
	return (1);
}

int	is_valid_pid(int pid)
{
	if (kill(pid, 0) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putendl_fd("\033[1;31mClient\033[0m -> wrong format\n\033[1;36m\
Try: './client <pid> <message>'\033[0m", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!is_valid_pid(pid))
	{
		ft_putendl_fd("\033[1;31mClient\033[0m -> wrong PID\n\033[1;36m\
The PID provided is not correct\033[0m", 1);
		return (1);
	}
	if (!send_message(argv[2], pid))
	{
		ft_putendl_fd("\033[1;31mClient\033[0m -> problem sending message", 1);
		return (1);
	}
	ft_putendl_fd("\033[1;32mClient\033[0m -> message sent", 1);
	return (0);
}
