/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:03:53 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:41:20 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char	*s;

	if (!str)
		return (NULL);
	s = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		++str;
	}
	return (s);
}
