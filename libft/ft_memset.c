/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:53:56 by jalbiser          #+#    #+#             */
/*   Updated: 2023/10/25 13:27:55 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *p, int v, size_t count)
{
	unsigned char	*ptr;

	ptr = p;
	while (count-- > 0)
	{
		*ptr++ = (unsigned char)v;
	}
	return (p);
}
