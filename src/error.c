/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 16:32:56 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

static void	aux_error(char error, char *msg)
{
	if (error == DELWIN)
		failn("Delwin failed.");
	else if (error == ENUM)
		failn("Invalid WIN_VALUE.");
	else if (error == COLOR)
		failn("Your terminal does not support color.");
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
