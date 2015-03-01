/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:16:56 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 10:52:38 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling multi windows with ncurses lib
*/

#include "header.h"

static void	print_nb(int nb, WINDOW *win)
{
	int		x;
	int		y;
	int		size;
	int		tmp;

	if (nb == EMPTY)
		return ;
	tmp = nb;
	size = 1;
	while (tmp /= 10)
		size++;
	getmaxyx(win, y, x);
	mvwprintw(win, y / 2, x / 2 - size / 2, "%d", nb);
}

static void	draw_win(t_env *e)
{
	int		 i;
	int		 j;

	i = -1;
	while (j = -1, e->win[++i])
		while (e->win[i][++j])
		{
			if ((wclear(e->win[i][j])) == ERR)
				error(WCLEAR, NULL);
			if ((wborder(e->win[i][j], '|', '|', '-', '-', '+', '+', '+', '+'))\
				== ERR)
				error(WBORDER, NULL);
			print_nb(e->num[j][i], e->win[i][j]);
			if ((wrefresh(e->win[i][j])) == ERR)
				error(WREFR, NULL);
		}
	if ((wclear(e->win_score)) == ERR)
		error(WCLEAR, NULL);
	if ((wborder(e->win_score, '|', '|', '~', '~', 'o', 'o', 'o', 'o')) == ERR)
		error(WBORDER, NULL);
	mvwprintw(e->win_score, 1, COLS / 2 - 5, "Score: %d", e->score);
	if ((wrefresh(e->win_score)) == ERR)
		error(WREFR, NULL);
}
/*
static void	clear_win(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->grid_size)
	{
		j = -1;
		while (++j < e->grid_size)
		{
//			if ((wborder(e->win[i][j], ' ', ' ', ' ',' ',' ',' ',' ',' '))		== ERR)
//				error(WBORDER, NULL);
			if ((wclear(e->win[i][j])) == ERR)
				error(WCLEAR, NULL);
//			if ((delwin(e->win[i][j])) == ERR)
//				error(DELWIN, NULL);
		}
	}
//	if ((wborder(e->win_score, ' ', ' ', ' ',' ',' ',' ',' ',' ')) == ERR)
//		error(WBORDER, NULL);
	if ((wclear(e->win_score)) == ERR)
		error(WCLEAR, NULL);
//	if ((delwin(e->win_score)) == ERR)
//		error(DELWIN, NULL);
}
*/
static void		move_resize(t_env *e)
{
	int		i;
	int		j;
	int		stop_i_j[2];
	int		start;

	stop_i_j[0] = COLS - (COLS % e->grid_size);
	stop_i_j[1] = LINES - (LINES % e->grid_size) - 1;
	start = (COLS - (e->grid_size ) * (stop_i_j[0] / e->grid_size - 1)) / 2;
	if ((wclear(e->win_score)) == ERR)
		error(WCLEAR, NULL);
	wresize(e->win_score, 3, stop_i_j[0] - start); //check errors
	mvwin(e->win_score, LINES - 3, start); //check errors
	i = -1;
	while (++i < e->grid_size)
	{
		j = -1;
		while (++j < e->grid_size)
		{
			if ((wclear(e->win[i][j])) == ERR)
				error(WCLEAR, NULL);
			wresize(e->win[i][j], stop_i_j[1] / e->grid_size,			\
					stop_i_j[0] / e->grid_size);
			mvwin(e->win[i][j], j * (stop_i_j[1] / e->grid_size - 1),	\
				  start + i * (stop_i_j[0] / e->grid_size - 1));
		}
	}
	refresh();
	draw_win(e);
}

void	refresh_win(t_env *e, char clear)
{
	int		i;
	int		j;
	int		stop_i_j[2];
	int		start;

	clear();
	if (clear)
		return (move_resize(e));
	stop_i_j[0] = COLS - (COLS % e->grid_size);
	stop_i_j[1] = LINES - (LINES % e->grid_size) - 1;
	start = (COLS - (e->grid_size ) * (stop_i_j[0] / e->grid_size - 1)) / 2;
	if (!(e->win_score = newwin(3, stop_i_j[0] - start, LINES - 3, start)))
		error(NEW_WIN, NULL);
	i = -1;
	while (++i < e->grid_size)
	{
		j = -1;
		while (++j < e->grid_size)
			if (!(e->win[i][j] = newwin(stop_i_j[1] / e->grid_size,\
		stop_i_j[0] / e->grid_size, j * (stop_i_j[1] / e->grid_size - 1),\
		start + i * (stop_i_j[0] / e->grid_size - 1))))
				error(NEW_WIN, NULL);
	}
	refresh();
	draw_win(e);
}
