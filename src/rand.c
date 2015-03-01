/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:26:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 12:31:04 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return an int between a and b
** give different seed to return different int at the same time
** seed must be >= 1
*/

#include "header.h"

int rand_a_b(int a, int b, int seed)
{
	srand(time(NULL) * seed);
	return (rand() % (b - a) + a);
}
