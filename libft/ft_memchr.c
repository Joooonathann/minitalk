/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:16:11 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/06 08:42:51 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *mb, int s, size_t size)
{
	unsigned char	*mbs;
	unsigned char	sc;
	size_t			i;

	i = 0;
	mbs = (unsigned char *) mb;
	sc = (unsigned char) s;
	while (i < size)
	{
		if (mbs[i] == sc)
			return ((void *)(mbs + i));
		i++;
	}
	return (NULL);
}
