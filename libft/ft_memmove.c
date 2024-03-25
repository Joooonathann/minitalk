/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:18:47 by jalbiser          #+#    #+#             */
/*   Updated: 2023/10/20 06:19:13 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	d = (char *) dest;
	s = (char *) src;
	if (d < s)
	{
		while (size--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += size;
		s += size;
		while (size--)
			*(--d) = *(--s);
	}
	return (dest);
}
