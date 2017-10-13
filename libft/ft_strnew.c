/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:55:58 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 17:24:28 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	(mem = (char*)malloc((size + 1) * sizeof(char)));
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
