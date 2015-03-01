/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:17:31 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 19:26:32 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		new_game(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (e->num[i])
	{
		j = 0;
		while (e->num[i][j])
		{
			e->num[i][j] = EMPTY;
			j++;
		}
		i++;
	}
	e->score = 0;
	pop_rand_num(e, 2, 7), pop_rand_num(e, two_or_four(), 8);
}

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
	else if (key == KEY_P && !is_tab_full(e))
		pop_rand_num(e, two_or_four(), 3);
	else if (key == KEY_N)
		new_game(e);
	if (!is_tab_full(e) && e->move && key != KEY_P && key != KEY_N)
		pop_rand_num(e, two_or_four(), 3);
}
