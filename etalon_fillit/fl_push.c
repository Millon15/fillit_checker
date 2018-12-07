/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:43:21 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 12:05:56 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fl_push(t_counter *count, t_handler *handl, t_node *row)
{
	t_node	*r;

	handl->soll[count->nodes++] = row;
	r = row->r;
	while (r != row)
	{
		handl->soll[count->nodes++] = r;
		r = r->r;
	}
}
