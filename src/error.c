/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 14:14:34 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

int			check_size(int y, int x)
{
	if (y < 3 || x < 6)
		return (0);
	return (1);
}

void		check_enum(size_t j)
{
	size_t		i;

	i = 2;
	while (i < j && i < 3000000000)
		i *= 2;
	if (i != j)
		error(ENUM, NULL);
	if (i == 2147483648)
	{
		i = 1;
		while (i < 20000000)
		{
			i *= 2;
			i /= 2;
			i++;
		}
	}
}

static void	aux_error(char error, char *msg)
{
	if (error == DELWIN)
		failn("Delwin failed.");
	else if (error == ENUM)
		failn("Invalid WIN_VALUE.");
	msg = msg;
}

void		error(char error, char *msg)
{
	endwin();
	if (error == USAGE)
		fail("Usage: "), fail(msg), failn(USAGE_MSG);
	else if (error == MALLOC)
		fail("Malloc failed with var: "), fail(msg), failn(".");
	else if (error == BUS)
		failn("Bus error.");
	else if (error == SEG)
		failn("Segmentation fault.");
	else if (error == FPE)
		failn("Floating point exception.");
	else if (error == WIN_LOC)
		failn("Window outside screen.");
	else if (error == NEW_WIN)
		failn("Creating new window failed.");
	else if (error == WCLEAR)
		failn("Wclear failed.");
	else if (error == WBORDER)
		failn("Wborder failed.");
	else if (error == WREFR)
		failn("Wrefresh failed.");
	else
		aux_error(error, msg);
	exit(-1);
}
