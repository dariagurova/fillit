/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:51:19 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 16:27:47 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	char		find;
	size_t		i;

	str = s;
	find = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
