/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:34 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/06 08:38:46 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_elem;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new_elem = ft_lstnew(tmp);
		if (!new_elem)
		{
			free(tmp);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_elem);
		lst = lst->next;
	}
	return (result);
}
