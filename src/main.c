/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 22:20:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main :P
*/

#include "header.h"

static int		two_or_four(void)
{
	int		i;

	i = 2;
	if (rand_a_b(1, 6, 57) == 3)
		i = 4;
	return (i);
}

static void	pop_rand_num(t_env *e, int n)
{
	unsigned int k;
	int		i;
	int		j;

	k = rand_a_b(1, ((e->grid_size) * (e->grid_size)) + 1, 974);
	if ((i = ((k + e->grid_size) % e->grid_size) - 1) < 0)
		i = 0;
	j = ((k - 1)/ e->grid_size);
	while (e->num[j][i] != EMPTY)
	{
		i++;
		if (i == e->grid_size)
		{
			i = 0;
			j++;
			if (j == e->grid_size)
			{
				i = 0;
				j = 0;
			}
		}
	}
	e->num[j][i] = n;
}

static void	init_game_tab(t_env *e)
{
	pop_rand_num(e, 2);
	pop_rand_num(e, two_or_four());
}

static void	bourre_a_gauche(int *line, int size)
{
	int		 j;
	int		 n;

	n = 0;
	while (n < size)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] == EMPTY && line[j + 1] != 0)
			{
				line[j] = line[j + 1];
				line[j + 1] = EMPTY;
			}
			j++;
		}
		n++;
	}
}

static void	add_a_gauche(int *line, t_env *e)
{
	int		 j;
	int		 n;

	n = 0;
	while (n < e->grid_size)
	{
		j = 0;
		while (line[j + 1] != 0)
		{
			if (line[j] == line[j + 1] && line[j] % 2 == 0)
			{
				line[j] *= 2;
				e->score += line[j];
				line[j + 1] = EMPTY;
			}
			j++;
		}
		n++;
	}
	bourre_a_gauche(line, e->grid_size);
}

static void	move_left(t_env *e)
{
	int		i;

	i = 0;
	while (e->num[i])
	{
		bourre_a_gauche(e->num[i], e->grid_size);
		add_a_gauche(e->num[i], e);
		i++;
	}
}

static void	bourre_a_droite(int *line, int size)
{
	int		 i;
	int		 n;

	n = 0;
	while (n < size)
	{
		i = size - 1;
		while (i - 1 >= 0)
		{
			if (line[i] == EMPTY && line [i - 1] != EMPTY)
			{
				line[i] = line[i - 1];
				line[i - 1] = EMPTY;
			}
			i--;
		}
		n++;
	}
}

static void	add_a_droite(int *line, t_env *e)
{
	int		 i;

	i = e->grid_size - 1;
	while (i - 1 >= 0)
	{
		if (line[i] == line[i - 1] && line[i] % 2 == 0)
		{
			line[i] *= 2;
			e->score += line[i];
			line[i - 1] = EMPTY;
		}
		i--;

	}
	bourre_a_droite(line, e->grid_size);
}

static void	move_right(t_env *e)
{
	int		 i;

	i = 0;
	while (e->num[i])
	{
		bourre_a_droite(e->num[i], e->grid_size);
		add_a_droite(e->num[i], e);
		i++;
	}
}

static void	bourre_en_haut(int i, t_env *e)
{
	int		j;
	int		n;

	j = 0;
	n = 0;
	while (n < e->grid_size)
	{
		while (e->num[j + 1])
		{
			if (e->num[j][i] == EMPTY && e->num[j + 1][i] != EMPTY)
			{
				e->num[j][i] = e->num[j + 1][i];
				e->num[j + 1][i] = EMPTY;
			}
			j++;
		}
		n++;
	}
}

static void	add_en_haut(int i, t_env *e)
{
	int		j;

	j = 0;
	while (e->num[j + 1])
	{
		if (e->num[j][i] == e->num[j + 1][i] && e->num[j][i] % 2 == 0)
		{
			e->num[j][i] *= 2;
			e->score += e->num[j][i];
			e->num[j + 1][i] = EMPTY;
		}
		j++;
	}
	bourre_en_haut(i, e);
}

static void	move_up(t_env *e)
{
	int		 i;

	i = 0;
	while (i < e->grid_size)
	{
		bourre_en_haut(i, e);
		add_en_haut(i, e);
		i++;
	}
}

static void	bourre_en_bas(int i, t_env *e)
{
	int		 j;
	int		 n;

	n = 0;
	while (n < e->grid_size)
	{
		j = e->grid_size -1;
		while (j - 1 >= 0)
		{
			if (e->num[j][i] == EMPTY && e->num[j - 1][i] != EMPTY)
			{
				e->num[j][i] = e->num[j - 1][i];
				e->num[j - 1][i] = EMPTY;
			}
			j--;
		}
		n++;
	}
}

static void	add_en_bas(int i, t_env *e)
{
	int		 j;

	j = e->grid_size - 1;
	while (j - 1 >= 0)
	{
		if (e->num[j][i] == e->num[j - 1][i] && e->num[j][i] % 2 == 0)
		{
			e->num[j][i] *= 2;
			e->score += e->num[j][i];
			e->num[j - 1][i] = EMPTY;
		}
		j--;
	}
	bourre_en_bas(i, e);
}

static void	move_down(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->grid_size)
	{
		bourre_en_bas(i, e);
		add_en_bas(i, e);
		i++;
	}
}

static void	make_ur_move(t_env *e, int key)
{
	if (key == KEY_UP)
		move_up(e);
	else if (key == KEY_DOWN)
		move_down(e);
	else if (key == KEY_LEFT)
		move_left(e);
	else if (key == KEY_RIGHT)
		move_right(e);
}

/*	      ^
** tpayet |
*/
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
	int			stop_i_j[2];
	int			start;

	stop_i_j[0] = COLS - (COLS % e->grid_size);
	stop_i_j[1] = LINES - (LINES % e->grid_size) - 1;
	start = (COLS - (e->grid_size ) * (stop_i_j[0] / e->grid_size - 1)) / 2;
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
	if (!(e->win_score = newwin(3, stop_i_j[0] - 4, LINES - 3,	2)))
		error(NEW_WIN, NULL);
	while (++i < e->grid_size)
	{
		j = -1;
		while (++j < e->grid_size)
			if (!(e->win[i][j] = newwin(stop_i_j[1] / e->grid_size,\
										stop_i_j[0] / e->grid_size,\
										j * (stop_i_j[1] / e->grid_size - 1),\
										start + i * (stop_i_j[0] / e->grid_size - 1))))
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
	init_game_tab(e);
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
	mvwprintw(win, y / 2, x / 2 - size / 2, "%d", nb);
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
	refresh();
}

int				main(int ac, char **av)
{
	t_env		e;
	int			key;

	
	ac != 1 ? error(USAGE, av[0]) : NULL;
	init(&e);
	while (42)
	{		
		init_win(&e, 42);
		draw_win(&e);
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
