/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_gauche.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:44:45 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:44:49 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		bourre_a_gauche(int *line, t_env *e)
{
	int		j;
	int		n;

	n = 0;
	while (n < e->grid_size)
	{
		j = 0;
		while (line[j + 1])
		{
			if (line[j] == EMPTY && line[j + 1] != EMPTY)
			{
				line[j] = line[j + 1];
				line[j + 1] = EMPTY;
				e->move = 1;
			}
			j++;
		}
		n++;
	}
}

static void		add_a_gauche(int *line, t_env *e)
{
	int		j;

	j = 0;
	while (j + 1 <= e->grid_size)
	{
		if (line[j] == line[j + 1] && line[j] % 2 == 0)
		{
			line[j] *= 2;
			e->score += line[j];
			line[j + 1] = EMPTY;
			e->move = 1;
		}
		j++;
	}
	bourre_a_gauche(line, e);
}

void			move_left(t_env *e)
{
	int		i;

	i = 0;
	while (e->num[i])
	{
		bourre_a_gauche(e->num[i], e);
		add_a_gauche(e->num[i], e);
		i++;
	}
}
