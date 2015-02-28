/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:02:37 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 07:09:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
//# define TRUE 1 //already defined in curses.h ?
//# define FALSE 0 //already defined in curses.h ?
# define KEY_ESC 27
# define USAGE_MSG "." //crazy stuff, hum?
# define USAGE 0
# define MALLOC 1
# define BUS 2
# define SEG 3
# define FPE 4
# define WIN_LOC 5
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h> //which one?
# include <ncurses.h> //which one?
# include <sys/time.h>

/*
** enum
*/
enum e_const
{
	WIN_VALUE = 2048 //???
};

/*
** struct && typedef
*/
typedef struct s_env	t_env;
struct		s_env
{
	t_char todo;
};

/*
** prototypes
*/
void			error(char error, char *msg);
void			sig_init(void);
int				get_key(void);

#endif
