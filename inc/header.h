/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:02:37 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 19:24:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define EMPTY 1
# define KEY_ESC 27
# define KEY_P 112
# define KEY_N 110
# define USAGE_MSG " [player name]."
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
# define ENUM 12
# define COLOR 13

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <time.h>
# include <fcntl.h>

/*
** enum
*/
enum			e_const
{
	WIN_VALUE = 8
};

/*
** struct && typedef
*/
typedef struct s_env	t_env;
struct			s_env
{
	WINDOW	***win;
	WINDOW	*win_score;
	int		score;
	int		**num;
	int		grid_size;
	char	*player;
	int		move;
};

/*
** prototypes
*/
int				is_tab_full(t_env *e);
int				is_won(t_env *e);
void			score(t_env *e);
int				game_over(t_env *e);
int				refresh_win(t_env *e, char clear);
int				two_or_four(void);
void			pop_rand_num(t_env *e, int n, int seed);
void			make_ur_move(t_env *e, int key);
int				rand_a_b(int a, int b, int seed);
int				check_size(int y, int x);
void			check_enum(size_t j);
void			error(char error, char *msg);
void			sig_init(void);
int				get_key(void);
void			move_up(t_env *e);
void			move_down(t_env *e);
void			move_right(t_env *e);
void			move_left(t_env *e);

#endif
