/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:08:03 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/26 18:08:07 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			res[ft_strlen(s)] = '\0';
			while (*s != '\0')
			{
				*(res + i) = f(i, *s);
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
