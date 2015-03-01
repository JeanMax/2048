/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:47:15 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:47:22 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		bourre_en_bas(int i, t_env *e)
{
	int		j;
	int		n;

	n = 0;
	while (n < e->grid_size)
	{
		j = e->grid_size - 1;
		while (j - 1 >= 0)
		{
			if (e->num[j][i] == EMPTY && e->num[j - 1][i] != EMPTY)
			{
				e->num[j][i] = e->num[j - 1][i];
				e->num[j - 1][i] = EMPTY;
				e->move = 1;
			}
			j--;
		}
		n++;
	}
}

static void		add_en_bas(int i, t_env *e)
{
	int		j;

	j = e->grid_size - 1;
	while (j - 1 >= 0)
	{
		if (e->num[j][i] == e->num[j - 1][i] && e->num[j][i] % 2 == 0)
		{
			e->num[j][i] *= 2;
			e->score += e->num[j][i];
			e->num[j - 1][i] = EMPTY;
			e->move = 1;
		}
		j--;
	}
	bourre_en_bas(i, e);
}

void			move_down(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->grid_size)
	{
		bourre_en_bas(i, e);
		add_en_bas(i, e);
		i++;
	}
}
