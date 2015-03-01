#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/03/01 09:40:19 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	game_2048
C_SRC = main.c error.c signal.c get_key.c rand.c window.c algo.c
I_DIR = -I./inc/
O_DIR =	obj
VPATH =	src
SRCC = 	$(C_SRC:%.c=src/%.c)
SRCO =	$(C_SRC:%.c=$(O_DIR)/%.o)
LIB =	libft/libft.a
INC =	inc/header.h
CC =	gcc
RM =	rm -f
CFLAGS = -Wall -Werror -Wextra
CURSES = -lncurses

.PHONY: all lib soft clean fclean zclean re brute

all: 
	@make -C libft
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(LIB) $(INC)
	$(CC) $(CFLAGS) $(I_DIR) $(SRCO) $(LIB) -o $@ $(CURSES)

$(O_DIR)/%.o: %.c
	@$(RM) $(NAME)
	$(CC) $(CFLAGS) $(I_DIR) -c $^ -o $@ $(CURSES)

soft:
	@$(RM) $(NAME)
	@$(CC) $(I_DIR) $(SRCC) $(LIB) -o $(NAME) $(CURSES) 

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

zclean: fclean
	@make -C libft fclean

re: fclean all

brute: zclean all
