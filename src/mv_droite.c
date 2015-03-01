/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_droite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:45:27 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:45:28 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		bourre_a_droite(int *line, t_env *e)
{
	int		i;
	int		n;

	n = 0;
	while (n < e->grid_size)
	{
		i = e->grid_size - 1;
		while (i - 1 >= 0)
		{
			if (line[i] == EMPTY && line[i - 1] != EMPTY)
			{
				line[i] = line[i - 1];
				line[i - 1] = EMPTY;
				e->move = 1;
			}
			i--;
		}
		n++;
	}
}

static void		add_a_droite(int *line, t_env *e)
{
	int		i;

	i = e->grid_size - 1;
	while (i - 1 >= 0)
	{
		if (line[i] == line[i - 1] && line[i] % 2 == 0)
		{
			line[i] *= 2;
			e->score += line[i];
			line[i - 1] = EMPTY;
			e->move = 1;
		}
		i--;
	}
	bourre_a_droite(line, e);
}

void			move_right(t_env *e)
{
	int			i;

	i = 0;
	while (e->num[i])
	{
		bourre_a_droite(e->num[i], e);
		add_a_droite(e->num[i], e);
		i++;
	}
}
