/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:41:25 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 09:47:35 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printlist(t_node *list)
{
	t_node	*current;
	int		i;

	i = 0;
	current = list;
	while (current != NULL)
	{
		if (ft_printchar(current->data) == -1)
			return (-1);
		current = current->next;
		i++;
	}
	return (i);
}
