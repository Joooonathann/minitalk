/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:32:56 by jalbiser          #+#    #+#             */
/*   Updated: 2024/05/21 20:53:58 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

int	exist_client(pid_t pid_client, t_clients **clients)
{
	t_clients	*client;

	client = *clients;
	if (!client)
		return (0);
	while (client)
	{
		if (client->pid == pid_client)
			return (1);
		client = client->next;
	}
	return (0);
}

void	delete_all_clients(t_clients **clients)
{
	t_clients	*tmp;

	if (!*clients)
		return ;
	while (*clients)
	{
		tmp = (*clients)->next;
		if ((*clients)->message)
			free((*clients)->message);
		free(*clients);
		*clients = tmp;
	}
	*clients = NULL;
}

void	delete_client(t_clients *client, t_clients **g_clients)
{
	t_clients	*current;
	t_clients	*previous;

	current = *g_clients;
	previous = NULL;
	while (current && current != client)
	{
		previous = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (previous == NULL)
		*g_clients = current->next;
	else
		previous->next = current->next;
	if (current->message)
		free(current->message);
	free(current);
}

t_clients	*get_client(pid_t pid_client, t_clients **g_clients)
{
	t_clients	*client;

	client = *g_clients;
	if (!client)
		return (NULL);
	while (client->pid != pid_client)
		client = client->next;
	return (client);
}
