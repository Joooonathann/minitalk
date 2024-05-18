/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createt_node.c                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:22:34 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:26:38 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_node	*createt_node(char data, t_node *stock)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		ft_freestock(stock);
		return (NULL);
	}
	new->data = data;
	new->next = NULL;
	if (stock == NULL)
		return (new);
	current = stock;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (stock);
}
