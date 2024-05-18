/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:48:58 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 09:52:45 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_node	*ft_stock(const char *format, va_list args)
{
	t_node	*stock;

	stock = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			stock = ft_flags(*format, stock, args);
		}
		else
			stock = createt_node(*format, stock);
		format++;
	}
	return (stock);
}
