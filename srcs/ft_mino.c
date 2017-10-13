/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mino.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:12:44 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 09:12:46 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "libft.h"

static	t_mino	*create_new_mino(char letter)
{
	t_mino *res;

	res = (t_mino*)malloc(sizeof(t_mino));
	if (res)
	{
		res->letter = letter;
		res->next = NULL;
		res->prev = NULL;
		res->i = (int*)malloc(sizeof(int) * 4);
		res->j = (int*)malloc(sizeof(int) * 4);
		res->height = 0;
		res->width = 0;
		res->left_width = 0;
		res->x = -1;
		res->y = -1;
	}
	return (res);
}

t_mino			*make_list(int count)
{
	t_mino	*list;
	t_mino	*tmp;
	t_mino	*begin;
	int		i;

	begin = NULL;
	if (count > 0)
		begin = create_new_mino('A');
	list = begin;
	i = 1;
	while (i < count)
	{
		tmp = create_new_mino(('A' + i));
		tmp->prev = list;
		list->next = tmp;
		list = list->next;
		i++;
	}
	return (begin);
}

int				validate_mino(t_mino *elem)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (i < 4)
	{
		w += weight(elem, i);
		i++;
	}
	if (w < 6)
		return (0);
	return (1);
}

static int		add_ij(char *str, t_mino **elem)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (*str == FULL)
			{
				if (k == 4)
					return (0);
				(*elem)->i[k] = i;
				(*elem)->j[k] = j;
				k++;
			}
			str++;
		}
		str++;
	}
	return (k);
}

int				fill_list(char *str, t_mino **list)
{
	t_mino	*begin;
	int		i;
	int		check;

	if (!list)
		return (0);
	begin = *list;
	i = 0;
	while (begin)
	{
		if ((check = add_ij(str, &begin)) != 4)
			return (0);
		if ((check = validate_mino(begin)) == 0)
			return (0);
		i++;
		begin = begin->next;
		str = str + 21;
	}
	return (1);
}
