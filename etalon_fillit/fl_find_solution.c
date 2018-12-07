/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:57:23 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 12:21:09 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		iter_loop(t_counter *count, t_handler *handl,
				t_node *header, t_node *r)
{
	while (r != header)
	{
		fl_push(count, handl, r);
		r = r->r;
		while (r->h != header)
		{
			fl_cover(handl, r->h);
			r = r->r;
		}
		fl_find_solution(count, handl, header->r);
		r = r->l;
		while (r->h != header)
		{
			fl_uncover(handl, r->h);
			r = r->l;
		}
		r = r->d;
		fl_pop(count, handl);
	}
}

void			fl_find_solution(t_counter *count, t_handler *handl,
				t_node *header)
{
	t_node		*r;

	if (header == handl->root || !handl->root->r->sign ||
	handl->root->r->sign[0] < 'A' ||
	count->nodes == 5 * count->counter)
		fl_print_solution(count, handl);
	if (header->sign[0] < 'A')
		return ;
	fl_cover(handl, header);
	r = header->d;
	iter_loop(count, handl, header, r);
	fl_uncover(handl, header);
}
