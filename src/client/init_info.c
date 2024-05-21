/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:59:26 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 19:15:31 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

static int	is_valid_pid(pid_t pid)
{
	if (kill(pid, SIGUSR1) == 0)
		return (1);
	else
		return (0);
}

int	init_info(pid_t pid_server, char *message, t_info *info)
{
	if (is_valid_pid(pid_server))
		info->pid = pid_server;
	else
	{
		ft_printf("Error: the pid is incorrect\n");
		return (0);
	}
	if (message)
	{
		info->message = ft_strdup(message);
		if (!info->message)
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
	return (1);
}
