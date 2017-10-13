/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:13:28 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/06 14:09:41 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "libft.h"

/*
** square root from number
*/

static int	ft_sqrt(int nb)
{
	int x1;
	int x2;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	x1 = nb / 2;
	x2 = (x1 + (nb / x1)) / 2;
	while ((x1 - x2) >= 1)
	{
		x1 = x2;
		x2 = (x1 + (nb / x1)) / 2;
	}
	return (x2);
}

/*
** smalest square size to start
*/

int			square_size(int count)
{
	int		size;
	int		res;

	res = 4 * count;
	size = ft_sqrt(res);
	size = (size * size < res ? size + 1 : size);
	return (size);
}

void		zero_list(t_mino *lst)
{
	while (lst)
	{
		lst->x = -1;
		lst->y = -1;
		lst = lst->next;
	}
}

/*
** solver , start from min square size
*/

void		solve(int size, t_mino *list)
{
	int		square;
	char	**matrix;
	int		check;

	matrix = NULL;
	square = square_size(size);
	hitgh_width(&list);
	get_result_matrix(&matrix, square);
	while ((check = try_to_fill(list, &matrix, square)) != 1)
	{
		zero_list(list);
		square++;
		get_result_matrix(&matrix, square);
	}
	print_result(matrix, square);
}

int			try_to_fill(t_mino *element, char ***matrix, int len)
{
	if (element == NULL)
		return (1);
	if (!find_next_available(element, matrix, len))
	{
		if (element->prev == NULL)
			return (0);
		step_back(matrix, element->prev);
		return (try_to_fill(element->prev, matrix, len));
	}
	return (try_to_fill(element->next, matrix, len));
}
