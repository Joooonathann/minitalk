/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:55:59 by jalbiser          #+#    #+#             */
/*   Updated: 2024/03/22 09:52:33 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int isValidStr(const char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	handler(int signal)
{
	static int	bit = 0;
	static char	i = 0;
	static char	*str = NULL;

	if (str == NULL) 
		str = ft_strdup("");

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		char *tmp = ft_strjoin(str, &i); // Stocker la nouvelle chaîne dans une variable temporaire
		free(str); // Libérer la mémoire de l'ancienne chaîne
		str = tmp; // Affecter la nouvelle chaîne à str
		bit = 0;
		i = 0;
	}
	if (isValidStr(str))
	{
		ft_putstr_fd(str, 1);
	   	free(str); // Libérer la mémoire de la chaîne après utilisation
		str = NULL;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 1)
	{
		ft_putendl_fd("\033[1;31mClient\033[0m -> wrong format\n\033[1;36mTry: './server'\033[0m", 1);
		return (1);
	}
	pid = getpid();
	ft_putstr_fd("\033[1;32mServer\033[0m -> ", 1);
	ft_putendl_fd(ft_itoa(pid), 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1);
	return (0);
}