/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 20:52:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main :P
*/

#include "header.h"

static int		**init_num_tab(int grid_size)
{
	int			**tab;
	int			i;
	int			j;

	if (!(tab = (int **)malloc(sizeof(int *) * (grid_size + 1))))
		error(MALLOC, "num_tab_Y");
	i = 0;
	while (i <= grid_size)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * (grid_size + 1))))
			error(MALLOC, "num_tab_X");
		i++;
	}
	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
			tab[i][j++] = EMPTY; //filled with '1' if it's not a num we'll print
		tab[i][grid_size] = 0; //segfault preventing
		i++;
	}
	tab[grid_size] = NULL;	//segfault preventing
//you can now use the int **tab as a char **tab! watch and see
/*
	i = 0;
	j = 0;
	while (tab[i])
	{
	j = 0;
	while (tab[i][j])
	ft_debugnbr("num", tab[i][j++]);
	ft_putendl("");
	i++;
	}
	exit(0);
*/
	return (tab);
}

static WINDOW	***init_win_tab(int grid_size)
{
	WINDOW		***tab;
	int			i;

	if (!(tab = malloc(sizeof(WINDOW **) * (grid_size + 1))))
		error(MALLOC, "win_tab_Y");
	i = 0;
	while (i <= grid_size)
	{
		if (!(tab[i] = malloc(sizeof(WINDOW *) * (grid_size + 1))))
			error(MALLOC, "win_tab_X");
		i++;
	}
	i = 0;
	while (i < grid_size)
	{
		tab[i][grid_size] = NULL; //segfault preventing
		i++;
	}
	tab[grid_size] = NULL;	//segfault preventing
	return (tab);
}

static void		init_win(t_env *e, char destroy)
{
	int			i;
	int			j;
	int			stop_i;
	int			stop_j;

	stop_i = COLS - (COLS % e->grid_size);
	stop_j = LINES - (LINES % e->grid_size) - 1;
	i = -1;
	if (destroy)
	{
		while (++i < e->grid_size)
		{
			j = -1;
			while (++j < e->grid_size)
			{
				if ((wborder(e->win[i][j], ' ', ' ', ' ',' ',' ',' ',' ',' ')) == ERR)
					error(WBORDER, NULL);
				if ((wclear(e->win[i][j])) == ERR)
					error(WCLEAR, NULL);
				if ((delwin(e->win[i][j])) == ERR)
					error(DELWIN, NULL);
			}
		}
		if ((wborder(e->win_score, ' ', ' ', ' ',' ',' ',' ',' ',' ')) == ERR)
			error(WBORDER, NULL);
		if ((wclear(e->win_score)) == ERR)
			error(WCLEAR, NULL);
		if ((delwin(e->win_score)) == ERR)
			error(DELWIN, NULL);
	}
	i = -1;
	clear();
	if (!(e->win_score = newwin(3, stop_i - 4, LINES - 3,	2)))
		error(NEW_WIN, NULL);
	while (++i < e->grid_size)
	{
		j = -1;
		while (++j < e->grid_size)
			if (!(e->win[i][j] = newwin(stop_j / e->grid_size,\
										stop_i / e->grid_size,\
										j * (stop_j / e->grid_size - 1),\
										i * (stop_i / e->grid_size - 1))))
				error(NEW_WIN, NULL);
	}
	refresh();
}

static void		init(t_env *e)
{
	int		key;

//sig_init();
	initscr();
	cbreak(); //one char at a time
	keypad(stdscr, TRUE); // keyboard mapping
	noecho(); //suppress the automatic echoing of typed characters
	e->score = 0;
	e->win_score = malloc(sizeof(WINDOW *));
	while (42)
	{
		printw("Press Esc at anytime to exit.\n\n");
		key = 2;
		while (key < 10)
			printw("Press %d to play in %dx%d.\n", key, key, key), key++;
		refresh();
		key = get_key();
		if (key >= 50 && key <= 57)
		{
			e->grid_size = key - 48;
			clear();
			break ;
		}
		clear();
	}
	e->num = init_num_tab(e->grid_size);
	e->old_num = init_num_tab(e->grid_size);
	e->win = init_win_tab(e->grid_size);
	init_win(e, 0);
}

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
	mvwprintw(win, y / 2, x / 2 - size / 2, "%d", nb + 2048);
}

static void		draw_win(t_env *e)
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
			print_nb(e->num[i][j], e->win[i][j]);
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
	refresh();
}

int				main(int ac, char **av)
{
	t_env		e;

	ac != 1 ? error(USAGE, av[0]) : NULL;
	init(&e);
	while (42)
		init_win(&e, 42), draw_win(&e), get_key();
	ft_freestab((void *)e.num); //won't happen, but swag
	endwin();
	return (0);
}
