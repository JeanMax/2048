/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:38:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 19:13:51 by mcanal           ###   ########.fr       */
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
		return (0);
	else if (key == KEY_ESC)
		endwin(), exit(0);
	return (key);
}
