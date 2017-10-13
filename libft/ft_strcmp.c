/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:12:08 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:15:08 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	str1;
	unsigned char	str2;

	str1 = *s1;
	str2 = *s2;
	while (str1 == str2 && str1)
	{
		str1 = (unsigned char)*s1++;
		str2 = (unsigned char)*s2++;
	}
	return (str1 - str2);
}
