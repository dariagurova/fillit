/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:09:14 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:25:36 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((len + 1) * sizeof(char));
		if (res == NULL)
			return (NULL);
		res[len] = '\0';
		while (i < len)
		{
			*(res + i) = *(s + start);
			i++;
			start++;
		}
		return (res);
	}
	return (NULL);
}
