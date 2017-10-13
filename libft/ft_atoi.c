/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:33:26 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/04 14:07:27 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long long	check;

	sign = 1;
	i = 0;
	check = 0;
	while (ft_spaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		check = check * 10 + (str[i] - 48);
		i++;
	}
	if (check > 9223372036854775807)
		return (sign == 1 ? -1 : 0);
	return (int)(check * sign);
}
