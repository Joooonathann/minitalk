/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:34:59 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 20:45:33 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../printf/include/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_clients
{
	pid_t				pid;
	char				*message;
	char				c;
	int					bits;
	int					len_message;
	struct s_clients	*next;
}						t_clients;

int						exist_client(pid_t pid_client, t_clients **clients);
void					delete_all_clients(t_clients **clients);
void					delete_client(t_clients *client, t_clients **g_clients);
t_clients				*get_client(pid_t pid_client, t_clients **g_clients);

#endif