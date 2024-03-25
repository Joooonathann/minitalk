/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:48:58 by jalbiser          #+#    #+#             */
/*   Updated: 2023/10/25 11:17:45 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	size_t	i;

	i = 0;
	while (str[i] != (char)s)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(str + i));
}
