/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:16:17 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:40:19 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (little[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)big);
	while (big[i])
	{
		while (little[pos] == big[i + pos])
		{
			if (pos == len - 1)
				return ((char *)big + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
