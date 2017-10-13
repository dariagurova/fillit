/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:14:51 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 16:52:47 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (src > dst)
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (len > 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
	return (dst);
}
