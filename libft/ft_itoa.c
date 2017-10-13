/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:42:18 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 18:09:10 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int		i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	int		len;

	is_neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strndup("-2147483648", 11));
		is_neg = 1;
		n = -n;
	}
	len = get_digits(n) + is_neg + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
