/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_create_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:50:04 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 09:53:35 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node		*fl_create_link(t_node *last, t_node *header, char *link_name)
{
	t_node	*link;

	link = (t_node *)malloc(sizeof(t_node));
	if (last)
	{
		link->l = last;
		link->r = last->r;
		(link->r)->l = link;
		(link->l)->r = link;
	}
	else
	{
		link->l = link;
		link->r = link;
	}
	link->h = header;
	link->u = header->u;
	link->d = header;
	(link->u)->d = link;
	(link->d)->u = link;
	header->size++;
	link->sign = ft_strdup(link_name);
	return (link);
}
