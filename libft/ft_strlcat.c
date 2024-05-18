/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:18:02 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/06 08:42:06 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ld;

	i = 0;
	ld = ft_strlen(dest);
	if (size <= ld)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && i < (size - ld - 1))
	{
		dest[ld + i] = src[i];
		i++;
	}
	dest[ld + i] = '\0';
	return (ld + ft_strlen(src));
}
