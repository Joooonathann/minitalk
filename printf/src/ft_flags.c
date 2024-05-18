/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:52:53 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:11:37 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_node	*ft_flags(char c, t_node *stock, va_list args)
{
	if (c == 'c')
		stock = createt_node(va_arg(args, int), stock);
	else if (c == 's')
		stock = ft_pushstr(va_arg(args, char *), stock);
	else if (c == 'p')
	{
		stock = ft_pushstr("0x", stock);
		stock = ft_convert_ptr(va_arg(args, unsigned long long), stock);
	}
	else if (c == 'd' || c == 'i')
		stock = ft_pushint(va_arg(args, int), stock);
	else if (c == 'u')
		stock = ft_pushintunsigned(va_arg(args, unsigned int), stock);
	else if (c == 'x')
		stock = ft_convert(va_arg(args, unsigned int), stock, hexa_min);
	else if (c == 'X')
		stock = ft_convert(va_arg(args, unsigned int), stock, hexa_max);
	else if (c == '%')
		stock = createt_node('%', stock);
	else
	{
		stock = createt_node('%', stock);
		stock = createt_node(c, stock);
	}
	return (stock);
}
