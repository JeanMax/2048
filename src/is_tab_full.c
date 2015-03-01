/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tab_full.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:55:04 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:55:46 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				is_tab_full(t_env *e)
{
	int		i;
	int		j;

	j = 0;
	while (e->num[j])
	{
		i = 0;
		while (e->num[j][i])
		{
			if (e->num[j][i] == EMPTY)
				return (0);
			if (e->num[j][i] == WIN_VALUE)
				return (WIN_VALUE);
			i++;
		}
		j++;
	}
	return (1);
}
