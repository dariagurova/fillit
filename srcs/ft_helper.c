/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:19:00 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 16:19:02 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "libft.h"

void	get_result_matrix(char ***res, int sqr)
{
	int i;
	int	j;

	if (*res)
	{
		i = -1;
		while (++i < (sqr - 1))
			free((*res)[i]);
		free(*res);
	}
	(*res) = (char **)malloc(sizeof(char*) * (sqr));
	i = -1;
	while (++i < sqr)
	{
		(*res)[i] = (char *)malloc(sizeof(char) * (sqr + 1));
		j = -1;
		while (++j < sqr)
			(*res)[i][j] = EMPTY;
		(*res)[i][sqr] = '\0';
	}
}

int		weight(t_mino *e, int pos)
{
	int weight;
	int	index;

	weight = 0;
	index = -1;
	while (++index < 4)
	{
		if (pos == index)
			index++;
		if (index == 4)
			return (weight);
		if (e->i[index] == (e->i[pos] - 1) && e->j[pos] == e->j[index])
			weight++;
		if (e->i[index] == e->i[pos] && e->j[pos] == (e->j[index] - 1))
			weight++;
		if (e->i[index] == (e->i[pos] + 1) && e->j[pos] == e->j[index])
			weight++;
		if (e->i[index] == e->i[pos] && e->j[pos] == (e->j[index] + 1))
			weight++;
	}
	return (weight);
}

void	clear_tail(t_mino *e)
{
	while (e->next)
	{
		(e->next)->x = -1;
		(e->next)->y = -1;
		e = e->next;
	}
}

void	step_back(char ***res, t_mino *e)
{
	int	i;
	int	j;
	int sqr;

	i = -1;
	sqr = ft_strlen((*res)[0]);
	if (*res)
	{
		if ((*res)[0])
		{
			while (++i < sqr)
			{
				j = -1;
				while (++j < sqr)
				{
					if ((*res)[i][j] == e->letter)
						(*res)[i][j] = EMPTY;
				}
			}
		}
	}
	clear_tail(e);
}

/*
** try to put tetrimino on position (i : j) in the matrix
*/

int		try_mino(char ***matrix, t_mino *elem, int i, int j)
{
	int x;
	int y;
	int c;

	x = elem->i[0];
	y = elem->j[0];
	c = -1;
	while (++c < 4)
	{
		if ((*matrix)[i - x + elem->i[c]][j - y + elem->j[c]] != EMPTY)
		{
			step_back(matrix, elem);
			return (0);
		}
		(*matrix)[i - x + elem->i[c]][j - y + elem->j[c]] = elem->letter;
		if (c == 0)
		{
			elem->x = i - x + elem->i[c];
			elem->y = j - y + elem->j[c];
		}
	}
	return (1);
}
