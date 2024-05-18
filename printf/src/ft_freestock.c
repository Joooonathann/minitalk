/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:35:18 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:37:29 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_freestock(t_node *stock)
{
	t_node	*current;
	t_node	*next;

	current = stock;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
