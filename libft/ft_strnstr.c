/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:10:43 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/06 08:40:54 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	s;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while ((big[i] != '\0') && (i < len))
	{
		s = 0;
		while ((big[i + s] == little[s]) && ((i + s) < len))
		{
			if (little[s + 1] == '\0')
				return ((char *)&big[i]);
			s++;
		}
		i++;
	}
	return (NULL);
}
