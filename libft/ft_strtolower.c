/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:28:46 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:41:47 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char	*s;

	if (!str)
		return (NULL);
	s = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		++str;
	}
	return (s);
}
