/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:36:17 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 11:36:18 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_node	*ft_convert_ptr(unsigned long long n, t_node *stock)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		stock = ft_convert_ptr(n / 16, stock);
	c = hex[n % 16];
	return (createt_node(c, stock));
}
