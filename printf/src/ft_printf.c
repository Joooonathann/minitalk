/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 05:21:57 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 09:40:54 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_node	*list;
	va_list	args;
	int		count;

	va_start(args, format);
	list = ft_stock(format, args);
	va_end(args);
	count = ft_printlist(list);
	ft_freestock(list);
	return (count);
}
