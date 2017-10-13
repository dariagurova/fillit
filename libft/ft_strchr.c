/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:24:47 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:16:22 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char find)
{
	char	c;

	while ((c = *str))
	{
		if (c == find)
			return ((char *)str);
		str++;
	}
	if (find == '\0')
		return ((char *)str);
	return (NULL);
}
