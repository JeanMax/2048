/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istoobig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 21:28:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/15 21:37:20 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check if an array will be higher than int_max after atoi
*/

#include "libft.h"

int				ft_istoobig(char *s)
{
	t_char		i;
	t_char		neg;

	neg = *s == '-' ? 1 : 0;
	s += *s == '-' ? 1 : 0;
	i = -1;
	while (ft_isdigit((int)s[++i]) && i < 12)
		;
	if (i != 10)
		return (i > 10 ? 1 : 0);
	if (*s > 50 || (*s == 50 && *(s + 1) > 49) || (*s == 50 && *(s + 1) == 49 \
	&& *(s + 2) > 52) || (*s == 50 && *(s + 1) == 49 && *(s + 2) == 52 && \
	*(s + 3) > 55) || (*s == 50 && *(s + 1) == 49 && *(s + 2) == 52 && *(s + 3)\
	== 55 && *(s + 4) > 52) || (*s == 50 && *(s + 1) == 49 && *(s + 2) == 52 &&\
	*(s + 3) == 55 && *(s + 4) == 52 && *(s + 5) > 56) || (*s == 50 && *(s + 1)\
	== 49 && *(s + 2) == 52 && *(s + 3) == 55 && *(s + 4) == 52 && *(s + 5) == \
	56 && *(s + 6) > 51) || (*s == 50 && *(s + 1) == 49 && *(s + 2) == 52 && \
	*(s + 3) == 55 && *(s + 4) == 52 && *(s + 5) == 56 && *(s + 6) == 51 && \
	*(s + 7) > 54) || (*s == 50 && *(s + 1) == 49 && *(s + 2) == 52 && *(s + 3)\
	== 55 && *(s + 4) == 52 && *(s + 5) == 56 && *(s + 6) == 51 && *(s + 7) == \
	54 && *(s + 8) > 52) || (*s == 50 && *(s + 1) == 49 && *(s + 2) == 52 && \
	*(s + 3) == 55 && *(s + 4) == 52 && *(s + 5) == 56 && *(s + 6) == 51 && \
	*(s + 7) == 54 && *(s + 8) == 52 && *(s + 9) > (neg ? 56 : 55)))
		return (1);
	return (0);
}
