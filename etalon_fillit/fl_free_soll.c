/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_free_soll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:28:31 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 11:24:28 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fl_free_soll(t_counter *count, t_handler *handl)
{
	t_node	*node;

	while (count->nodes != 0)
	{
		count->nodes += 4;
		node = fl_pop(count, handl);
		fl_uncover(handl, node);
		fl_delete_link(handl, node);
	}
	free(handl->soll);
	handl->soll = NULL;
	count->nodes = 0;
}
