# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalbiser <jalbiser@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 20:58:44 by jalbiser          #+#    #+#              #
#    Updated: 2024/05/21 21:33:01 by jalbiser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE_PRINTF = @make -C printf
MAKE_LIBFT = @make -C libft
PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT = 	./src/client/client.c\
				./src/client/init_info.c

SRC_SERVER =	./src/server/client_process.c\
				./src/server/server.c

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(MAKE_LIBFT)
	$(MAKE_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(MAKE_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(NAME_SERVER)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE_LIBFT) clean
	$(MAKE_PRINTF) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE_LIBFT) fclean
	$(MAKE_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re