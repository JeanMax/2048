/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:56:00 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:56:07 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				game_over(t_env *e)
{
	int i;
	int j;

	i = 0;
	if (!is_tab_full(e))
		return (0);
	while (e->num[i + 1])
	{
		j = 0;
		while (e->num[i][j + 1])
		{
			if (e->num[i][j] == e->num[i][j + 1] || \
				e->num[i][j] == e->num[i + 1][j])
				return (0);
			j++;
		}
		i++;
	}
	i = e->grid_size - 1;
	j = i;
	if (e->num[i][j] == e->num[i][j - 1] || \
		e->num[i][j] == e->num[i - 1][j])
		return (0);
	return (1);
}
