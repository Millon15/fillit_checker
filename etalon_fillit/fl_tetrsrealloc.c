/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_tetrsrealloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:22:18 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 10:23:28 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fl_tetrsrealloc(t_handler *handl, t_counter *count)
{
	t_tetrimino		**new_tetrs;
	unsigned short	i;

	new_tetrs = (t_tetrimino **)malloc(sizeof(t_tetrimino*) *
		++(count->counter));
	i = 0;
	while (i < count->counter - 1)
	{
		new_tetrs[i] = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		new_tetrs[i]->rows = handl->tetrs[i]->rows;
		new_tetrs[i]->colls = handl->tetrs[i]->colls;
		new_tetrs[i]->sign = handl->tetrs[i]->sign;
		ft_memcpy(new_tetrs[i]->shape, handl->tetrs[i]->shape,
			sizeof(unsigned short) * 16);
		i++;
	}
	new_tetrs[i] = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	fl_tetrsfree(handl, count);
	handl->tetrs = new_tetrs;
}
