/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 18:50:20 by dgurova           #+#    #+#             */
/*   Updated: 2017/09/24 14:08:48 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = ft_strlen(str);
	while (i > -1)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	return (NULL);
}
