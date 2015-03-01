/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_won.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:22:54 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 19:23:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check is WIN_VALUE is found on the grid
*/

#include "header.h"

int             is_won(t_env *e)
{
	int     i;
	int     j;

	j = -1;
	while (i = -1, e->num[++j])
		while (e->num[j][++i])
			if (e->num[j][i] == WIN_VALUE)
				return (1);
	return (0);
}
