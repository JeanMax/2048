/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:36:39 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 19:15:41 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** highscore!
*/

#include "header.h"

static void		put_it(t_env *e, int fd)
{
	ft_putnbr_fd(e->score, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(e->player, fd);
	ft_putstr_fd(" in ", fd);
	ft_putnbr_fd(e->grid_size, fd);
	ft_putstr_fd("x", fd);
	ft_putnbr_fd(e->grid_size, fd);
	ft_putendl_fd("", fd);
}

void			score(t_env *e)
{
	int			fd;
	char		*previous;
	char		*useless;

	fd = open("highscore", O_RDWR);
	get_all(fd, &previous);
	if (ft_atoi(previous) <= e->score)
	{
		close(fd);
		fd = open("highscore", O_WRONLY);
		put_it(e, fd);
		get_all(fd, &useless);
		ft_putstr_fd(previous, fd);
	}
	close(fd);
	fd = open("highscore", O_RDWR);
	get_all(fd, &previous);
}
