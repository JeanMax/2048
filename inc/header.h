/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:02:37 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 20:20:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define SIZE_X 4 //size of the grid, it would better to ask for these at the begining
# define SIZE_Y 4 //idem
# define EMPTY 1
# define KEY_ESC 27
# define USAGE_MSG "."
# define USAGE 1
# define MALLOC 2
# define BUS 3
# define SEG 4
# define FPE 5
# define WIN_LOC 6
# define NEW_WIN 7
# define WCLEAR 8
# define WBORDER 9
# define WREFR 10
# define DELWIN 11
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h>
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
	WINDOW	***win; //window point from curses
	int		**num; //just the numbers on screen
	int		**old_num; //just the previous numbers on screen
	int		grid_size;
	WINDOW	*win_score;
	int		score;
};

/*
** prototypes
*/
void			error(char error, char *msg);
void			sig_init(void);
int				get_key(void);

#endif
