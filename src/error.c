/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 05:32:16 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

void		error(char error, char *msg)
{
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
	exit(-1);
}
