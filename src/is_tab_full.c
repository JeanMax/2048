/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tab_full.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:55:04 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 19:23:20 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				is_tab_full(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	while (i = -1, e->num[++j])
		while (e->num[j][++i])
			if (e->num[j][i] == EMPTY)
				return (0);
	return (1);
}
