/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_gettetrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:28:41 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 17:01:53 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			fl_tetrsinit(t_handler *handl, t_counter *cnt)
{
	handl->tetrs[cnt->counter - 1]->rows = 0;
	handl->tetrs[cnt->counter - 1]->colls = 0;
	handl->tetrs[cnt->counter - 1]->sign = 'A' + cnt->counter - 1;
}

void				fl_get_tetrs(t_handler *handl, t_counter *cnt,
					char *file)
{
	int				fd;
	ssize_t			ret;
	char			buff[21];
	int				k;

	if ((fd = open(file, O_RDONLY)) == -1)
		fl_puterr("error\n");
	cnt->counter = 0;
	k = 1;
	while ((ret = read(fd, buff, 21)) > -2)
		if ((ret == 21 && buff[20] == '\n') || ret == 20)
		{
			k = (ret == 21 ? 1 : 0);
			fl_tetrsrealloc(handl, cnt);
			fl_tetrsinit(handl, cnt);
			fl_tetrsadd(cnt, handl, buff);
		}
		else if (cnt->counter < 1)
			fl_puterr("error\n");
		else
			break ;
	close(fd);
	if (k == 1 || cnt->counter > 26)
		fl_puterr("error\n");
}
