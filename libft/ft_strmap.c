/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:55:43 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/26 17:55:55 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			res[ft_strlen(s)] = '\0';
			while (*s != '\0')
			{
				*(res + i) = f(*s);
				i++;
				s++;
			}
		}
		else
			return (NULL);
		return (res);
	}
	return (NULL);
}
