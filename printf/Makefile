# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 14:50:01 by jalbiser          #+#    #+#              #
#    Updated: 2023/12/01 05:22:45 by jalbiser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = 				libftprintf.a
CC = 				cc
INCLUDE =			include
CFLAGS = 			-Wall -Wextra -Werror -I $(INCLUDE)
MAKEFLAGS +=		--silent
SRC_DIR = 	src

SRC = 		ft_printf.c\
			createnode.c\
			ft_convert.c\
			ft_convert_ptr.c\
			ft_flags.c\
			ft_freestock.c\
			ft_printchar.c\
			ft_printlist.c\
			ft_pushint.c\
			ft_pushintunsigned.c\
			ft_pushstr.c\
			ft_stock.c

OBJ =		$(addprefix $(SRC_DIR)/, $(SRC:.c=.o))


all: 				$(NAME)

$(NAME): 			$(OBJ)
					@echo "\n🕒 Compilation en cours de $(NAME)...\n"
					ar rcs $(NAME) $(OBJ)
					@echo "\n✅ \033[0;32mCompilation de $(NAME) effectué\033[0m\n"

clean:
					rm -f $(SRC_DIR)/*.o

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
