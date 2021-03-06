#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 21:26:32 by mcanal            #+#    #+#              #
#    Updated: 2015/02/15 21:30:59 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I inc/
INC = inc/libft.h
CC = gcc
AR = ar rc
RM = rm -f
VPATH = edit/lst1:edit/lst2:io:is:lst1:lst2:mem:str
O_DIR = obj
C_EDIT1 =	ft_lstnew.c			ft_lstmap.c			ft_lstdelone.c		\
			ft_lstfind.c
C_EDIT2 =	ft_lnew.c			ft_lfree.c 			ft_lfind.c
C_IO =		ft_putchar.c		ft_putnbr.c			ft_putstr.c			\
			ft_putendl.c		ft_putchar_fd.c		get_all.c			\
			ft_putendl_fd.c		ft_putstr_fd.c		get_next_line.c		\
			ft_putstr_clr.c		ft_putchar_clr.c	ft_putendl_clr.c	\
			ft_debugstr.c		ft_debugnbr.c		ft_putnbr_clr.c		\
			get_line.c			fail.c				failn.c				\
			ft_putnbr_fd.c
C_IS =		ft_isalnum.c		ft_isalpha.c		ft_isxdigit.c		\
			ft_isascii.c		ft_isdigit.c		ft_isprint.c		\
			ft_islower.c		ft_isupper.c		ft_isblank.c		\
			ft_iscntrl.c		ft_isgraph.c		ft_isspace.c		\
			ft_ispunct.c		ft_istoobig.c
C_LST1 =	ft_lstlast.c		ft_lstdel.c			ft_lstiter.c		\
			ft_lstadd.c			ft_lstaddlast.c		ft_lstlen.c			\
			ft_lstat.c			ft_lstisempty.c		ft_lstislast.c		\
			ft_lstinser.c		ft_lstrplc.c		ft_lstisn.c			\
			ft_lstdellink.c
C_LST2 =	ft_ladd.c			ft_laddlast.c		ft_lat.c			\
			ft_ldellink.c		ft_lfirst.c			ft_lisfirst.c		\
			ft_linser.c			ft_lisempty.c		ft_lclean.c			\
			ft_lislast.c		ft_lisn.c			ft_liter.c			\
			ft_llast.c			ft_llen.c			ft_lrplc.c			\
			ft_lswap.c
C_MEM =		ft_bzero.c			ft_memccpy.c		ft_memchr.c			\
			ft_memcmp.c			ft_memcpy.c			ft_memmove.c		\
			ft_memset.c			ft_memalloc.c		ft_memdel.c			\
			ft_realloc.c		ft_freestab.c		ft_cpystab.c
C_STR =		ft_strindex.c		ft_strrindex.c		ft_strcpy.c			\
			ft_atoi.c			ft_strcat.c			ft_strcmp.c			\
			ft_strdup.c			ft_strlen.c			ft_strncpy.c		\
			ft_strstr.c			ft_tolower.c		ft_toupper.c		\
			ft_strchr.c			ft_strlcat.c		ft_strsplit.c		\
			ft_strncat.c		ft_strncmp.c		ft_strnstr.c		\
			ft_strdel.c			ft_strjoin.c		ft_strnew.c			\
			ft_strequ.c			ft_strmap.c			ft_strrchr.c		\
			ft_striter.c		ft_strmapi.c		ft_strsub.c			\
			ft_strclr.c			ft_striteri.c		ft_strnequ.c		\
			ft_itoa.c			ft_strtrim.c		ft_strndup.c
SRCC =	$(C_EDIT1:%.c=edit/lst1/%.c)		$(C_EDIT2:%.c=edit/lst2/%.c)\
		$(C_IO:%.c=io/%.c)					$(C_IS:%.c=is/%.c)			\
		$(C_LST1:%.c=lst1/%.c)				$(C_LST2:%.c=lst2/%.c)		\
		$(C_MEM:%.c=mem/%.c)				$(C_STR:%.c=str/%.c)
SRCO =	$(C_EDIT1:%.c=$(O_DIR)/%.o)			$(C_EDIT2:%.c=$(O_DIR)/%.o)	\
		$(C_IO:%.c=$(O_DIR)/%.o)			$(C_IS:%.c=$(O_DIR)/%.o)	\
		$(C_LST1:%.c=$(O_DIR)/%.o)			$(C_LST2:%.c=$(O_DIR)/%.o)	\
		$(C_MEM:%.c=$(O_DIR)/%.o)			$(C_STR:%.c=$(O_DIR)/%.o)

.PHONY: all clean fclean re

all:
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(INC)
	@$(AR) $(NAME) $(SRCO)
	@ranlib $(NAME) || $(RM) $(NAME)

$(O_DIR)/%.o: %.c
	@$(CC) -c $(CFLAGS) $^ -o $@ || $(RM) $(NAME)

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
