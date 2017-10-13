/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:55:04 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/23 18:34:07 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*str1;
	const char	*str2;
	size_t		i;
	size_t		j;

	j = 0;
	i = ft_strlen(s1);
	str1 = s1;
	str2 = s2;
	while (j < ft_strlen(s2) && j < n)
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return (str1);
}
