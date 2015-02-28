#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/28 06:17:10 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	game_2048
C_SRC = main.c error.c signal.c
O_DIR =	obj
VPATH =	src
SRCC = 	$(C_SRC:%.c=src/%.c)
SRCO =	$(C_SRC:%.c=$(O_DIR)/%.o)
LIB =	libft/libft.a /usr/lib64/libncurses.a
INC =	inc/header.h
CC =	gcc
RM =	rm -f
CFLAGS = -Wall -Werror -Wextra -I./inc/ -I/usr/include/ -lncurses

.PHONY: all lib soft clean fclean zclean re

all: 
	@make -C libft
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(LIB) $(INC)
	$(CC) $(CFLAGS) $(SRCO) $(LIB) -o $@

$(O_DIR)/%.o: %.c
	@$(RM) $(NAME)
	$(CC) $(CFLAGS) $(LIB) -c $^ -o $@

soft:
	@$(RM) $(NAME)
	@$(CC) -I./inc/ $(SRCC) $(LIB) -o $(NAME)
	@./$(NAME)

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

zclean: fclean
	@make -C libft fclean

re: fclean all

