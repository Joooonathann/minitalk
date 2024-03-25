/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:35:48 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/03 16:10:14 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	size_t	i;

	i = ft_strlen(str);
	while (str[i] != (char) s)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char *)(str + i));
}
