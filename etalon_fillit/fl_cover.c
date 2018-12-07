/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_cover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:49:43 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 10:13:34 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fl_cover(t_handler *handl, t_node *header)
{
	t_node	*row_node;

	row_node = header->d;
	header->r->l = header->l;
	header->l->r = header->r;
	while (row_node != header)
	{
		row_node = row_node->r;
		while (row_node->h != header)
		{
			row_node->u->d = row_node->d;
			row_node->d->u = row_node->u;
			row_node->h->size--;
			row_node = row_node->r;
		}
		row_node = row_node->d;
	}
	(handl->root->size)--;
}
