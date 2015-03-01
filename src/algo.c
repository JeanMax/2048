/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:17:31 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/01 09:26:32 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** game's algo
*/

#include "header.h"

static void	bourre_a_gauche(int *line, int size)
{
	int		 j;
	int		 n;

	n = 0;
	while (n < size)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] == EMPTY && line[j + 1] != 0)
			{
				line[j] = line[j + 1];
				line[j + 1] = EMPTY;
			}
			j++;
		}
		n++;
	}
}

static void	add_a_gauche(int *line, t_env *e)
{
	int		 j;
	int		 n;

	n = 0;
	while (n < e->grid_size)
	{
		j = 0;
		while (line[j + 1] != 0)
		{
			if (line[j] == line[j + 1] && line[j] % 2 == 0)
			{
				line[j] *= 2;
				e->score += line[j];
				line[j + 1] = EMPTY;
			}
			j++;
		}
		n++;
	}
	bourre_a_gauche(line, e->grid_size);
}

static void	move_left(t_env *e)
{
	int		i;

	i = 0;
	while (e->num[i])
	{
		bourre_a_gauche(e->num[i], e->grid_size);
		add_a_gauche(e->num[i], e);
		i++;
	}
}

static void	bourre_a_droite(int *line, int size)
{
	int		 i;
	int		 n;

	n = 0;
	while (n < size)
	{
		i = size - 1;
		while (i - 1 >= 0)
		{
			if (line[i] == EMPTY && line [i - 1] != EMPTY)
			{
				line[i] = line[i - 1];
				line[i - 1] = EMPTY;
			}
			i--;
		}
		n++;
	}
}

static void	add_a_droite(int *line, t_env *e)
{
	int		 i;

	i = e->grid_size - 1;
	while (i - 1 >= 0)
	{
		if (line[i] == line[i - 1] && line[i] % 2 == 0)
		{
			line[i] *= 2;
			e->score += line[i];
			line[i - 1] = EMPTY;
		}
		i--;

	}
	bourre_a_droite(line, e->grid_size);
}

static void	move_right(t_env *e)
{
	int		 i;

	i = 0;
	while (e->num[i])
	{
		bourre_a_droite(e->num[i], e->grid_size);
		add_a_droite(e->num[i], e);
		i++;
	}
}

static void	bourre_en_haut(int i, t_env *e)
{
	int		j;
	int		n;

	j = 0;
	n = 0;
	while (n < e->grid_size)
	{
		while (e->num[j + 1])
		{
			if (e->num[j][i] == EMPTY && e->num[j + 1][i] != EMPTY)
			{
				e->num[j][i] = e->num[j + 1][i];
				e->num[j + 1][i] = EMPTY;
			}
			j++;
		}
		n++;
	}
}

static void	add_en_haut(int i, t_env *e)
{
	int		j;

	j = 0;
	while (e->num[j + 1])
	{
		if (e->num[j][i] == e->num[j + 1][i] && e->num[j][i] % 2 == 0)
		{
			e->num[j][i] *= 2;
			e->score += e->num[j][i];
			e->num[j + 1][i] = EMPTY;
		}
		j++;
	}
	bourre_en_haut(i, e);
}

static void	move_up(t_env *e)
{
	int		 i;

	i = 0;
	while (i < e->grid_size)
	{
		bourre_en_haut(i, e);
		add_en_haut(i, e);
		i++;
	}
}

static void	bourre_en_bas(int i, t_env *e)
{
	int		 j;
	int		 n;

	n = 0;
	while (n < e->grid_size)
	{
		j = e->grid_size -1;
		while (j - 1 >= 0)
		{
			if (e->num[j][i] == EMPTY && e->num[j - 1][i] != EMPTY)
			{
				e->num[j][i] = e->num[j - 1][i];
				e->num[j - 1][i] = EMPTY;
			}
			j--;
		}
		n++;
	}
}

static void	add_en_bas(int i, t_env *e)
{
	int		 j;

	j = e->grid_size - 1;
	while (j - 1 >= 0)
	{
		if (e->num[j][i] == e->num[j - 1][i] && e->num[j][i] % 2 == 0)
		{
			e->num[j][i] *= 2;
			e->score += e->num[j][i];
			e->num[j - 1][i] = EMPTY;
		}
		j--;
	}
	bourre_en_bas(i, e);
}

static void	move_down(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->grid_size)
	{
		bourre_en_bas(i, e);
		add_en_bas(i, e);
		i++;
	}
}

int		two_or_four(void)
{
	int		i;

	i = 2;
	if (rand_a_b(1, 6, 57) == 3)
		i = 4;
	return (i);
}

void	pop_rand_num(t_env *e, int n)
{
	unsigned int k;
	int		i;
	int		j;

	k = rand_a_b(1, ((e->grid_size) * (e->grid_size)) + 1, 974);
	if ((i = ((k + e->grid_size) % e->grid_size) - 1) < 0)
		i = 0;
	j = ((k - 1)/ e->grid_size);
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

void	make_ur_move(t_env *e, int key)
{
	if (key == KEY_UP)
		move_up(e);
	else if (key == KEY_DOWN)
		move_down(e);
	else if (key == KEY_LEFT)
		move_left(e);
	else if (key == KEY_RIGHT)
		move_right(e);
}
