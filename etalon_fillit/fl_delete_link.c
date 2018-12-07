/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_delete_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:50:18 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 10:14:24 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node		*fl_delete_link(t_handler *handl, t_node *link)
{
	t_node	*temp;

	if (link != link->d)
		temp = link->d;
	else
		temp = NULL;
	if (link != handl->root)
	{
		link->r->l = link->l;
		link->l->r = link->r;
		link->u->d = link->d;
		link->d->u = link->u;
	}
	link->h = NULL;
	link->l = NULL;
	link->r = NULL;
	link->u = NULL;
	link->d = NULL;
	link->size = 0;
	if (link->sign)
		free(link->sign);
	free(link);
	return (temp);
}
