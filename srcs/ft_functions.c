/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:43:57 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 10:43:59 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "libft.h"

static	void	get_height(t_mino *elem)
{
	int min;
	int max;
	int i;

	i = 1;
	min = elem->i[0];
	max = elem->i[0];
	while (i < 4)
	{
		if (min > elem->i[i])
			min = elem->i[i];
		if (max < elem->i[i])
			max = elem->i[i];
		i++;
	}
	elem->height = (max - min + 1);
}

static void		get_width(t_mino *elem)
{
	int start;
	int stop;
	int left_stop;
	int i;

	start = elem->j[0];
	stop = elem->j[0];
	left_stop = elem->j[0];
	i = 0;
	while (++i < 4)
	{
		if (stop < elem->j[i])
			stop = elem->j[i];
		if (left_stop > elem->j[i])
			left_stop = elem->j[i];
	}
	elem->width = (stop - start + 1);
	elem->left_width = (left_stop - start);
}

void			hitgh_width(t_mino **lst)
{
	t_mino	*l;

	if (lst)
	{
		l = *lst;
		while (l)
		{
			get_height(l);
			get_width(l);
			l = l->next;
		}
	}
}

static void		get_start_position(t_mino *elem, int *i, int *j, int len)
{
	if (elem->y == len - 1)
	{
		elem->y = 0;
		elem->x = elem->x + 1;
	}
	else
		elem->y = elem->y + 1;
	*i = elem->x;
	*j = elem->y;
	if (elem->x < 0)
	{
		*i = 0;
		*j = 0;
	}
}

int				find_next_available(t_mino *elem, char ***matrix, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	get_start_position(elem, &i, &j, len);
	while (i < len)
	{
		while (j < len)
		{
			if (((len - j) >= elem->width) && ((len - i) >= elem->height)
				&& ((j + elem->left_width) >= 0) && ((*matrix)[i][j] == EMPTY))
			{
				elem->x = i;
				elem->y = j;
				if (try_mino(matrix, elem, elem->x, elem->y))
					return (1);
			}
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	return (0);
}
