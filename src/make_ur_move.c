/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:17:31 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:06:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			make_ur_move(t_env *e, int key)
{
	e->move = 0;
	if (key == KEY_UP)
		move_up(e);
	else if (key == KEY_DOWN)
		move_down(e);
	else if (key == KEY_LEFT)
		move_left(e);
	else if (key == KEY_RIGHT)
		move_right(e);
	if (!is_tab_full(e) && e->move)
		pop_rand_num(e, two_or_four(), 3);
}
