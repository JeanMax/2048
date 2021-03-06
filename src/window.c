/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:16:56 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 16:42:49 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling multi windows with ncurses lib
*/

#include "header.h"

static void		print_nb(int nb, WINDOW *win)
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
	wattron(win, COLOR_PAIR(5));
	mvwprintw(win, y / 2, x / 2 - size / 2, "%d", nb);
}

static void		draw_win(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (j = -1, e->win[++i])
		while (e->win[i][++j])
		{
			((wclear(e->win[i][j])) == ERR) ? error(WCLEAR, NULL) : NULL;
			wbkgd(e->win[i][j], COLOR_PAIR(6));
			wattron(e->win[i][j], COLOR_PAIR(4));
			if ((wborder(e->win[i][j], '|', '|', '-', '-', '+', '+', '+', '+'))\
				== ERR)
				error(WBORDER, NULL);
			print_nb(e->num[j][i], e->win[i][j]);
			((wrefresh(e->win[i][j])) == ERR) ? error(WREFR, NULL) : NULL;
		}
	wbkgd(e->win_score, COLOR_PAIR(5));
	wattron(e->win_score, COLOR_PAIR(4));
	refresh();
	((wclear(e->win_score)) == ERR) ? error(WCLEAR, NULL) : NULL;
	if ((wborder(e->win_score, '|', '|', '~', '~', 'o', 'o', 'o', 'o')) == ERR)
		error(WBORDER, NULL);
	wattron(e->win_score, COLOR_PAIR(5));
	mvwprintw(e->win_score, 1, COLS / 2 - 5, "Score: %d", e->score);
	((wrefresh(e->win_score)) == ERR) ? error(WREFR, NULL) : NULL;
}

static void		clear_win(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->grid_size)
	{
		j = -1;
		while (++j < e->grid_size)
		{
			if ((wborder(e->win[i][j], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '))\
				== ERR)
				error(WBORDER, NULL);
			if ((wclear(e->win[i][j])) == ERR)
				error(WCLEAR, NULL);
			if ((delwin(e->win[i][j])) == ERR)
				error(DELWIN, NULL);
		}
	}
	if ((wborder(e->win_score, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')) == ERR)
		error(WBORDER, NULL);
	if ((wclear(e->win_score)) == ERR)
		error(WCLEAR, NULL);
	if ((delwin(e->win_score)) == ERR)
		error(DELWIN, NULL);
}

int				refresh_win(t_env *e, char clear)
{
	int		i;
	int		j;
	int		stop_i_j[2];
	int		start;

	stop_i_j[0] = COLS - (COLS % e->grid_size);
	stop_i_j[1] = LINES - (LINES % e->grid_size) - 1;
	start = (COLS - (e->grid_size) * (stop_i_j[0] / e->grid_size - 1)) / 2;
	if (!check_size(stop_i_j[1] / e->grid_size,\
					stop_i_j[0] / e->grid_size) && clear)
	{
		clear(), printw("Window's too small.\nResize it!"), refresh();
		check_enum(2147483648);
		return (0);
	}
	clear ? clear_win(e) : NULL, clear(), i = -1, wbkgd(stdscr, COLOR_PAIR(5));
	if (!(e->win_score = newwin(3, stop_i_j[0] - 4, LINES - 3, 2)))
		error(NEW_WIN, NULL);
	while (j = -1, ++i < e->grid_size)
		while (++j < e->grid_size)
			if (!(e->win[i][j] = newwin(stop_i_j[1] / e->grid_size,\
		stop_i_j[0] / e->grid_size, j * (stop_i_j[1] / e->grid_size - 1),\
		start + i * (stop_i_j[0] / e->grid_size - 1))))
				error(NEW_WIN, NULL);
	return (refresh(), draw_win(e), 1);
}
