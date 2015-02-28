/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:02:37 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 13:21:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
//# define TRUE 1 //already defined in curses.h ?
//# define FALSE 0 //already defined in curses.h ?
# define MAX_X 2600 //max printable char on screen
# define MAX_Y 500 //idem
# define SIZE_X 4 //size of the grid, it would better to ask for these at the begining
# define SIZE_Y 4 //idem
# define EMPTY 1
# define KEY_ESC 27
# define USAGE_MSG "." //crazy stuff, hum?
# define USAGE 1
# define MALLOC 2
# define BUS 3
# define SEG 4
# define FPE 5
# define WIN_LOC 6
# define NEW_WIN 7
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h> //which one?
//# include <ncurses.h> //which one?
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
/*
typedef struct s_bord	t_bord;
struct		s_bord
{
	chtype ls;
	chtype rs;
	chtype ts;
	chtype bs;
	chtype tl;
	chtype tr;
	chtype bl;
	chtype br;
};

typedef struct s_win	t_win;
struct	s_win
{

	int		startx;
	int		starty;
	int		height;
	int		width;
	t_bord	border;
};
*/
typedef struct s_env	t_env;
struct		s_env
{
	WINDOW	*win; //window point from curses
//	int		x_max; //size of the term
//	int		y_max; //idem
	int		old_win_x;
	int		old_win_y;
//	char	scr[MAX_X + 1][MAX_Y + 1]; //what we want to print
//	int		num[SIZE_X + 1][SIZE_Y + 1]; //just the numbers on screen
	char	**scr; //what we want to print
	int		**num; //just the numbers on screen
};

/*
** prototypes
*/
void			error(char error, char *msg);
void			sig_init(void);
int				get_key(void);

#endif
