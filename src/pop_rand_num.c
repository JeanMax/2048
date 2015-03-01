/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_rand_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:54:43 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:54:52 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			pop_rand_num(t_env *e, int n, int seed)
{
	unsigned int	k;
	int				i;
	int				j;

	k = rand_a_b(1, ((e->grid_size) * (e->grid_size)) + 1, seed);
	if ((i = ((k + e->grid_size) % e->grid_size) - 1) < 0)
		i = 0;
	j = ((k - 1) / e->grid_size);
	while (e->num[j][i] != EMPTY)
	{
		i++;
		if (i == e->grid_size)
		{
			i = 0;
			j++;
			if (j == e->grid_size)
			{
				i = 0;
				j = 0;
			}
		}
	}
	e->num[j][i] = n;
}
