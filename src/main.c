/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 13:24:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main :P
*/

/*
                The screen (stdscr)
        (0,0)*----------------------------------* (0, ??-1)
             |                                  |
             |                                  |
             |    (??,??)                       |
             |      ---------------             |
             |      |             |             |
             |      |             |             |
             |      |     win     |LINES        |
             |      |             |             |
             |      |             |             |
             |      |             |             |
             |      ---------------             |
             |          COLS                    |
             |                                  |
             *----------------------------------*
       (??-1, 0)                              (??-1, ??-1) 

it would be nice to find the size of the screen in printable char
->depends on the police

max size with police 2 and full screen:
478/2550
*/

#include "header.h"

static void		init_num_tab(t_env *e)
{
	int			**tab;
	int			i;
	int			j;

	if (!(tab = (int **)malloc(sizeof(int *) * (SIZE_Y + 1))))
		error(MALLOC, "num_tab_Y");
	i = 0;
	while (i <= SIZE_Y)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * (SIZE_X + 1))))
			error(MALLOC, "num_tab_X");
		i++;
	}
	i = 0;
	while (i < SIZE_Y)
	{
		j = 0;
		while (j < SIZE_X)
			tab[i][j++] = EMPTY; //filled with '1' if it's not a num we'll print
		tab[i][SIZE_X] = 0; //segfault preventing
		i++;
	}
	tab[SIZE_Y] = NULL;  //segfault preventing
	e->num = tab;
	
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
}
/*
static void		init_scr_tab(t_env *e)
{
	char		**tab;
	int			i;
	int			j;

	if (!(tab = (char **)malloc(sizeof(char *) * (MAX_Y + 1))))
		error(MALLOC, "scr_tab_Y");
	i = 0;
	while (i <= MAX_Y)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (MAX_X + 1))))
			error(MALLOC, "scr_tab_X");
		i++;
	}
	i = 0;
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
			tab[i][j++] = ' '; //default filled with space
		tab[i][MAX_X] = '\0'; //segfault preventing
		i++;
	}
	tab[MAX_Y] = NULL;  //segfault preventing
	e->scr = tab;
}

static void		edit_scr_size(t_env *e)
{
	int			i;
	int			j;
	
	i = 0;
	while (i < LINES)
	{
		j = 0;
		while (j < COLS)
		{
			if (!i || !j || i == LINES - 1 || j == COLS - 1)
				e->scr[i][j] = 'X'; //border
			else
				e->scr[i][j] = 'z'; //default filled with space
			j++;
		}
		e->scr[i][j] = 'X'; //bottom right corner
		e->scr[i][COLS] = '\0'; //segfault preventing
		i++;
	}
	e->scr[LINES] = NULL;  //segfault preventing
}
*/
static void		init_win(t_env *e)
{
	if (!(e->win = newwin(LINES - 1, COLS - 1, 0, 0)))
		error(NEW_WIN, NULL);
	wborder(e->win, '|', '|', '-', '-', '+', '+', '+', '+'); //draw border...
	wrefresh(e->win);
}

static void		init(t_env *e)
{
//sig_init();
	initscr();
	cbreak(); //one char at a time
	keypad(stdscr, TRUE); // keyboard mapping
	noecho(); //suppress the automatic echoing of typed characters
	keypad(stdscr, TRUE); //allow arrow keys capture
//	getmaxyx(stdscr, e->y_max, e->x_max); //update y/x with COLS/LINES... useless?
	init_num_tab(e);
//	init_scr_tab(e);
//	edit_scr_size(e);
	printw("Press Esc to exit."); //print something in the win-buffer
	mvprintw(3, 5, "ZBOUB"); //	move to (3,5) and print zboub!
	printw("\nBOOBZ"); //print at the new cursor position
	refresh(); //print the win-buffer to terminal... right now win is the screen
	e->old_win_x = COLS;
	e->old_win_y = LINES;
}

int				main(int ac, char **av)
{
	t_env		e;

	if (ac != 1)
		error(USAGE, av[0]);
	init(&e);

	//debug
	int key;
//	int i;
	get_key();
	init_win(&e);
	while (42)
	{
//		getmaxyx(e.win, e.y_max, e.x_max); //update win size if term resized
		if (!(key = get_key())) //will pause the loop till a key is pressed
			continue ;
		if (e.old_win_x != COLS || e.old_win_y != LINES)
			wresize(e.win, LINES, COLS);
//		clear();
//		edit_scr_size(&e);
//		i = 0;
//		while (e.scr[i])
//			printw("%s", e.scr[i++]);
		wprintw(e.win, "\n key %d\n", key);
		wprintw(e.win," LINES %d\n", LINES);
		wprintw(e.win," COLS %d\n", COLS);
		wrefresh(e.win);
		e.old_win_x = COLS;
		e.old_win_y = LINES;
	}
 //debug

	ft_freestab((void *)e.scr); //won't happen, but swag
	ft_freestab((void *)e.num); //won't happen, but swag
	endwin();
	return (0);
}
