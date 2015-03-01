/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 09:43:50 by mcanal           ###   ########.fr       */
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
		tab[i][grid_size] = NULL; //segfault preventing
		i++;
	}
	tab[grid_size] = NULL;	//segfault preventing
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
	sig_init();
	initscr();
	cbreak(); //one char at a time
	keypad(stdscr, TRUE); // keyboard mapping
	noecho(); //suppress the automatic echoing of typed characters
	e->score = 0;
	menu_loop(e);
	e->win_score = malloc(sizeof(WINDOW *));
	e->num = init_num_tab(e->grid_size);
	e->win = init_win_tab(e->grid_size);
	refresh_win(e, 0);
	pop_rand_num(e, 2);
	pop_rand_num(e, two_or_four());
}

int				main(int ac, char **av)
{
	t_env		e;
	int			key;

	ac != 1 ? error(USAGE, av[0]) : NULL;
	init(&e);
	while (42)
	{
		refresh_win(&e, 42);
		key = get_key();
		if (key != KEY_DOWN && key != KEY_RIGHT && \
			key != KEY_UP && key != KEY_LEFT)
			continue ;
		make_ur_move(&e, key);
		pop_rand_num(&e, two_or_four());
	}
	ft_freestab((void *)e.num); //won't happen, but swag
	endwin();
	return (0);
}
