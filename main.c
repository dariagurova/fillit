/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:38:37 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/19 09:38:39 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "libft.h"

void	print_result(char **res, int sqr)
{
	int i;
	int j;

	i = -1;
	while (++i < sqr)
	{
		j = -1;
		while (++j < sqr)
			ft_putchar(res[i][j]);
		ft_putchar('\n');
	}
}

void	free_list(t_mino **begin_list)
{
	t_mino *curr;
	t_mino *next;

	if (begin_list)
	{
		curr = *begin_list;
		while (curr)
		{
			next = curr->next;
			free(curr->i);
			free(curr->j);
			free(curr);
			curr = next;
		}
		*begin_list = NULL;
	}
}

void	show_usage(void)
{
	ft_putstr("usage: fillit source_file\n");
}

void	error(char *str, t_mino **lst)
{
	ft_putstr("error\n");
	free_list(lst);
	free(str);
}

int		main(int argc, char **argv)
{
	char		*str;
	int			size;
	t_mino		*list;

	size = 0;
	if (argc == 2 && argv[1])
	{
		str = validate_input_file(argv[1], &size);
		if (size > 0 && size <= 26)
		{
			list = make_list(size);
			if (fill_list(str, &list))
			{
				solve(size, list);
				free_list(&list);
				free(str);
				return (0);
			}
		}
		error(str, &list);
	}
	else
		show_usage();
	return (0);
}
