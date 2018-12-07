/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_free_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:28:43 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 18:36:40 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fl_free_table(t_handler *handl)
{
	t_node *header;
	t_node *node;

	if (!handl->root)
		return ;
	header = handl->root->r;
	while (handl->root && header && header != handl->root)
	{
		node = header->d;
		while (header && node && node != header)
		{
			if (node)
				node = fl_delete_link(handl, node->u);
		}
		header = header->r;
		if (header)
			free(header->l);
	}
	if (handl->root != NULL)
		fl_delete_link(handl, handl->root);
	handl->root = NULL;
}
