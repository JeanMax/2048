/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:46:31 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:46:38 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		bourre_en_haut(int i, t_env *e)
{
	int		j;
	int		n;

	n = 0;
	while (n <= e->grid_size)
	{
		j = 0;
		while (e->num[j + 1])
		{
			if (e->num[j][i] == EMPTY && e->num[j + 1][i] != EMPTY)
			{
				e->num[j][i] = e->num[j + 1][i];
				e->num[j + 1][i] = EMPTY;
				e->move = 1;
			}
			j++;
		}
		n++;
	}
}

static void		add_en_haut(int i, t_env *e)
{
	int		j;

	j = 0;
	while (e->num[j + 1])
	{
		if (e->num[j][i] == e->num[j + 1][i] && e->num[j][i] % 2 == 0)
		{
			e->num[j][i] *= 2;
			e->score += e->num[j][i];
			e->num[j + 1][i] = EMPTY;
			e->move = 1;
		}
		j++;
	}
	bourre_en_haut(i, e);
}

void			move_up(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->grid_size)
	{
		bourre_en_haut(i, e);
		add_en_haut(i, e);
		i++;
	}
}
