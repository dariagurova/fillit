/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:16:52 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/02 14:16:55 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*tail;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		tail = malloc(sizeof(size_t));
		if (tail == NULL)
			return (NULL);
		tail = f(lst);
		if (!new)
		{
			new = tail;
			current = tail;
		}
		else
		{
			current->next = tail;
			current = current->next;
		}
		lst = lst->next;
	}
	return (new);
}
