/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 15:26:13 by mcanal           ###   ########.fr       */
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
			tab[i][j++] = EMPTY;
		tab[i][grid_size] = 0;
		i++;
	}
	tab[grid_size] = NULL;
	return (tab);
}

static WINDOW	***init_win_tab(int grid_size)
{
	WINDOW		***tab;
	int			i;

	if (!(tab = (WINDOW ***)malloc(sizeof(WINDOW **) * (grid_size + 1))))
		error(MALLOC, "win_tab_Y");
	i = 0;
	while (i <= grid_size)
	{
		if (!(tab[i] = (WINDOW **)malloc(sizeof(WINDOW *) * (grid_size + 1))))
			error(MALLOC, "win_tab_X");
		i++;
	}
	i = 0;
	while (i < grid_size)
	{
		tab[i][grid_size] = NULL;
		i++;
	}
	tab[grid_size] = NULL;
	return (tab);
}

static void		menu_loop(t_env *e)
{
	int		key;

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
}

static void		init(t_env *e)
{
	check_enum(WIN_VALUE);
	sig_init();
	initscr();
	if (has_colors() == FALSE)
		error(COLOR, NULL);
	start_color();
	init_color(COLOR_BLUE, 956, 529, 529); //rouge
	init_color(COLOR_MAGENTA, 1000, 974, 533); //jaune
	init_color(COLOR_CYAN, 416, 965, 686); //vert
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_RED, COLOR_BLUE);
	init_pair(5, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(6, COLOR_GREEN, COLOR_CYAN);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	e->score = 0;
	menu_loop(e);
	e->win_score = malloc(sizeof(WINDOW *));
	e->num = init_num_tab(e->grid_size);
	e->win = init_win_tab(e->grid_size);
	refresh_win(e, 0);
	pop_rand_num(e, 2, 5);
	pop_rand_num(e, two_or_four(), 4);
}

int				main(int ac, char **av)
{
	t_env		e;
	int			key;

	ac != 1 ? error(USAGE, av[0]) : NULL;
	init(&e);
	while (42)
	{
		if (!refresh_win(&e, 42))
			continue ;
		key = get_key();
		if ((key != KEY_DOWN && key != KEY_RIGHT && \
			key != KEY_UP && key != KEY_LEFT))
			continue ;
		if (game_over(&e))
			break;
		make_ur_move(&e, key);
	}
	clear(), mvprintw(LINES / 2, COLS / 2 - 8,  ">< Game Over ><"), refresh();
	get_key();
	ft_freestab((void *)e.num); //won't happen, but swag
	endwin();
	return (0);
}
