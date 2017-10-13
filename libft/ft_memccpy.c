/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:42:23 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 16:27:19 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		if (s[i] == c)
		{
			return ((void*)&d[i + 1]);
		}
		i++;
	}
	return (NULL);
}
