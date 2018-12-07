/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_tetrsfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:23:34 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 10:27:23 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				fl_tetrsfree(t_handler *handl, t_counter *count)
{
	unsigned short	index;

	if (!(handl->tetrs))
		return ;
	index = 0;
	while (index < count->counter - 1)
		free(handl->tetrs[index++]);
	free(handl->tetrs);
	handl->tetrs = NULL;
}
