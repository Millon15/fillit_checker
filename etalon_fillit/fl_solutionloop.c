/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_solutionloop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:25:52 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 12:54:19 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	fl_get_min_square(unsigned short i)
{
	unsigned short j;

	j = 0;
	while (j * j < i)
		j++;
	return (j);
}

static void		fl_init_struct(t_handler *handl, t_counter *count)
{
	count->counter = 0;
	count->nodes = 0;
	count->size = 0;
	handl->tetrs = NULL;
	handl->soll = NULL;
	handl->root = NULL;
}

void			fl_solutionloop(int argc, char **argv)
{
	t_handler	handl;
	t_counter	count;

	if (argc != 2)
		fl_puterr("usage: fillit source_file\n");
	fl_init_struct(&handl, &count);
	fl_get_tetrs(&handl, &count, argv[1]);
	count.size = fl_get_min_square((unsigned short)(4 *
		(count.counter)));
	while (TRUE)
	{
		fl_form_rows(&count, &handl);
		handl.soll = (t_node **)malloc(sizeof(t_node *) * 5
			* count.counter);
		fl_find_solution(&count, &handl, (handl.root)->r);
		fl_free_soll(&count, &handl);
		fl_free_table(&handl);
		(count.size)++;
	}
}
