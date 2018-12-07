/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_uncover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:18:57 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 10:26:15 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fl_uncover(t_handler *handl, t_node *header)
{
	t_node	*row_node;

	row_node = header->u;
	header->r->l = header;
	header->l->r = header;
	while (row_node != header)
	{
		row_node = row_node->l;
		while (row_node->h != header)
		{
			row_node->u->d = row_node;
			row_node->d->u = row_node;
			row_node->h->size++;
			row_node = row_node->l;
		}
		row_node = row_node->u;
	}
	(handl->root->size)++;
}
