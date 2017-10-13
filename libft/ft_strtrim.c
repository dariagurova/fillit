/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:08:08 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/03 18:14:22 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s, size_t *start)
{
	size_t		len;
	size_t		i;

	len = 0;
	if (s)
		len = ft_strlen(s);
	if (len == 0)
		return (0);
	i = 0;
	while (ft_spaces(*(s + i)) && *(s + i) != '\0')
		i++;
	if (i == len)
		return (0);
	while (len > 0)
	{
		if (ft_spaces(*(s + len - 1)))
			len--;
		else
			break ;
	}
	*start = i;
	return (len - i);
}

char			*ft_strtrim(char const *s)
{
	size_t		new_len;
	char		*new;
	size_t		start;
	size_t		i;

	new_len = get_len(s, &start);
	if (new_len == 0)
		new = (char*)malloc(1 * sizeof(char));
	else
		new = (char*)malloc((new_len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[new_len] = '\0';
	i = 0;
	while (i < new_len)
	{
		*(new + i) = *(s + start);
		i++;
		start++;
	}
	return (new);
}
