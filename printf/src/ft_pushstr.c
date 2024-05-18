/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:18:40 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:20:40 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_node	*ft_pushstr(char *str, t_node *stock)
{
	if (!str)
	{
		stock = ft_pushstr("(null)", stock);
		return (stock);
	}
	while (*str)
	{
		stock = createt_node(*str, stock);
		str++;
	}
	return (stock);
}
