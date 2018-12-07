/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:41:57 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 10:42:27 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node		*fl_pop(t_counter *count, t_handler *handl)
{
	int		i;
	t_node	*node;

	i = count->nodes - 5;
	node = (handl->soll)[i];
	while (i != count->nodes)
		handl->soll[--(count->nodes)] = NULL;
	return (node);
}
