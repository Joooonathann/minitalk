/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:50:14 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 19:14:55 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../printf/include/ft_printf.h"
# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	char	*message;
	pid_t	pid;
	int		bits;
	int		index;
}			t_info;

int	init_info(pid_t pid_server, char *message, t_info *info);

#endif