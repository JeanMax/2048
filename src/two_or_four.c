/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_or_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:54:19 by tpayet            #+#    #+#             */
/*   Updated: 2015/03/01 16:54:32 by tpayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				two_or_four(void)
{
	int		i;

	i = 2;
	if (rand_a_b(1, 6, 57) == 3)
		i = 4;
	return (i);
}
