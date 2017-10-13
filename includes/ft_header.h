/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:48:28 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/19 09:48:30 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 128
# define EMPTY  '.'
# define FULL '#'

typedef struct		s_mino
{
	int				*i;
	int				*j;
	char			letter;
	int				height;
	int				width;
	int				left_width;
	struct s_mino	*next;
	struct s_mino	*prev;
	int				x;
	int				y;
}					t_mino;

char				*validate_input_file(char *file, int *tetrimino_count);
int					square_size(int count);
t_mino				*make_list(int count);
int					fill_list(char *str, t_mino **list);
int					validate_mino(t_mino *elem);
void				free_list(t_mino **begin_list);
void				solve(int size, t_mino *list);
void				get_result_matrix(char ***res, int sqr);
void				print_result(char **res, int sqr);
void				step_back(char ***res, t_mino *e);
int					try_to_fill(t_mino *element, char ***matrix, int len);
int					find_next_available(t_mino *elem, char ***matrix, int len);
int					try_mino(char ***matrix, t_mino *elem, int i, int j);
void				hitgh_width(t_mino **lst);
int					weight(t_mino *e, int i);

#endif
