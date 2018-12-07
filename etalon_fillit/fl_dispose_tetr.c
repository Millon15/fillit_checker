/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_dispose_tetr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:55:13 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 10:14:50 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				fl_dispose_tetr(t_counter *count, t_tetrimino *tetr,
					t_handler *handl, unsigned short *shape)
{
	t_node			*header;
	t_node			*last;
	unsigned short	index;
	char			*sign;

	index = 0;
	header = handl->root->r;
	while (header->sign && header->sign[0] != tetr->sign && ++index)
		header = header->r;
	last = fl_create_link(NULL, header, header->sign);
	sign = ft_strnew(ft_strlen(header->sign));
	ft_memcpy(sign, header->sign, sizeof(char) * (ft_strlen(header->sign)));
	sign[1] = '\0';
	while (index++ < count->counter)
		header = header->r;
	index = 0;
	while (header != handl->root)
	{
		if (shape[index++] == 1)
			last = fl_create_link(last, header, &(tetr->sign));
		header = header->r;
	}
	free(sign);
}
