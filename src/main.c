/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 05:52:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main :P
*/

/*
                The screen (stdscr)
        (0,0)*----------------------------------* (0, COLUMNS-1)
             |                                  |
             |                                  |
             |    (y0,x0)                       |
             |      ---------------             |
             |      |             |             |
             |      |             |             |
             |      |     win     |nlines       |
             |      |             |             |
             |      |             |             |
             |      |             |             |
             |      ---------------             |
             |          ncols                   |
             |                                  |
             *----------------------------------*
       (LINES-1, 0)                              (LINES-1, COLUMNS-1) 
*/

#include "header.h"

static void		init(void)
{
	ft_putstr("\033[2J\033[1;1H"); 
//clear... or wrefresh(win)/refresh()/wrefresh(stdscr) ?
	initscr();
	sig_init();
	cbreak(); //one char at a time
	keypad(stdscr, TRUE); // keyboard mapping
//	noecho(); //suppress the automatic echoing of typed characters
	keypad(stdscr, TRUE); //allow arrow keys capture
	if (x0 < 0 || y0 < 0 || (x0 + ncols) > COLUMNS-1 || (y0 + nlines) > LINES-1)
		error(WIN_LOC, NULL);
//"You should make sure that the area of the new window is inside the screen."
	WINDOW * win = newwin(nlines, ncols, y0, x0); //creating new window
}

int				main(int ac, char **av)
{
//	t_env		e; //TODO
	if (ac != 1)
		error(USAGE, av[0]);
	init();

 //debug
	while (42)
	{
		ft_debugnbr("LINES", LINES);
		ft_debugnbr("COLUMNS", COLUMNS);
		ft_debugnbr("x0", x0);
		ft_debugnbr("y0", y0);
		ft_debugnbr("ncols", ncols);
		ft_debugnbr("nlines", nlines);
		sleep(1);
	}
 //debug

	delwin(win), endwin();
	return (0);
}
