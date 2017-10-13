/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:30:54 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:07:50 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*res;
	size_t		i;

	res = b;
	i = 0;
	while (len > i)
	{
		*(res + i) = c;
		i++;
	}
	return (res);
}
