/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:03:48 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 12:06:10 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fl_print_solution(t_counter *count, t_handler *handl)
{
	unsigned short	i;
	unsigned short	j;

	i = 0;
	(count->counter)++;
	fl_tetrsfree(handl, count);
	while (i < count->size * count->size && !(j = 0))
	{
		while (j < count->nodes)
			if (((handl->soll[j]->h->sign[0] <= '9' &&
				handl->soll[j]->h->sign[0] >= '0' &&
				ft_atoi(handl->soll[j]->h->sign) == i) ||
				j == count->nodes - 1) && ++i)
			{
				ft_putchar(ft_atoi(handl->soll[j]->h->sign) == i - 1 ?
					handl->soll[j - 1]->sign[0] : '.');
				break ;
			}
			else
				j++;
		if (i - 1 != 0 && i % count->size == 0)
			ft_putchar('\n');
	}
	fl_free_table(handl);
	exit(0);
}
