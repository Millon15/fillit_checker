/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:42:24 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 16:59:28 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *list, t_list *(*f)(t_list *node))
{
	t_list	*head;
	t_list	*new;

	if (!list || !f)
		return (NULL);
	new = f(list);
	head = new;
	while (list->next)
	{
		list = list->next;
		if (!(new->next = f(list)))
		{
			free(new->next);
			return (NULL);
		}
		new = new->next;
	}
	return (head);
}
