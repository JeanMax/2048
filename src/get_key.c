/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:38:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 08:51:30 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** read typed keys! defines returned are :
** KEY_DOWN KEY_UP KEY_LEFT KEY_RIGHT KEY_ESC (this one is from header.h)
*/

#include "header.h"

int				get_key(void)
{
	int			key;

	if ((key = getch()) == ERR)
		return (0); // user hasn't responded
	else if (key == KEY_ESC)
		endwin(), exit(0); //exit allowed?
	return (key);
}
