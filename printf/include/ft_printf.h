/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:27:23 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/01 05:23:12 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct Node
{
	char			data;
	struct Node		*next;
}	t_node;

typedef enum types
{
	hexa_min,
	hexa_max
}	t_type;

int		ft_printf(const char *format, ...);
t_node	*createt_node(char data, t_node *stock);
t_node	*ft_convert(unsigned int n, t_node *stock, t_type t_type);
t_node	*ft_flags(char c, t_node *stock, va_list args);
int		ft_printchar(int data);
int		ft_printlist(t_node *list);
t_node	*ft_pushint(int i, t_node *stock);
t_node	*ft_pushintunsigned(unsigned int i, t_node *stock);
t_node	*ft_pushstr(char *str, t_node *stock);
t_node	*ft_stock(const char *format, va_list args);
void	ft_freestock(t_node *stock);
t_node	*ft_convert_ptr(unsigned long long n, t_node *stock);

#endif
