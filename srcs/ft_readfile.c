/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:45:21 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/19 09:45:23 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "libft.h"

static int		validate_file(char *str)
{
	int i;
	int	tetrimino_count;
	int j;

	j = -1;
	tetrimino_count = 0;
	while (*str && ++j >= 0)
	{
		i = 0;
		if (j == 4 && *str == '\n' && *(str + 1) != '\0')
		{
			j = 0;
			tetrimino_count++;
			str++;
		}
		while (i++ < 4 && *str != '\0')
		{
			if (*str != EMPTY && *str != FULL)
				return (0);
			str++;
		}
		if (*str == '\n')
			str++;
	}
	return (j == 3 ? (tetrimino_count + 1) : 0);
}

static char		*increase_buffer(unsigned int *buff_size, int fd)
{
	if (*buff_size < 2147483647 && fd != 0)
		*buff_size *= 2;
	return (malloc(*buff_size + 1));
}

static char		*read_input(int fd, unsigned int buff_size)
{
	char	*input;
	char	*buff;
	char	*tmp;
	int		cur;
	long	size;

	size = 0;
	buff = 0;
	input = malloc(buff_size + 1);
	while ((cur = read(fd, input, buff_size)) > 0)
	{
		input[cur] = '\0';
		tmp = buff;
		size += buff_size;
		buff = malloc(size + 1);
		if (tmp)
			ft_strcpy(buff, tmp);
		ft_strcat(buff, input);
		free(input);
		free(tmp);
		input = increase_buffer(&buff_size, fd);
	}
	free(input);
	return (buff);
}

/*
** validate input file , calculate tetrimino count
**        and return input file as a string
*/

char			*validate_input_file(char *file, int *tetrimino_count)
{
	int		fd;
	char	*content;

	content = NULL;
	*tetrimino_count = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		content = read_input(fd, BUFF_SIZE);
		if (content)
			*tetrimino_count = validate_file(content);
	}
	close(fd);
	return (content);
}
