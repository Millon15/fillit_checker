/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_tetrsadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:30:33 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 12:27:39 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			fl_processing(unsigned short *mtx, unsigned short *ind,
					char *buff)
{
	if (mtx[0] == 5 && mtx[1] == 5)
	{
		mtx[0] = ind[0];
		mtx[1] = ind[1];
		if (ind[1] != 0)
		{
			if ((ind[0] < 3 && buff[5 * (ind[0] + 1) + ind[1] - 1] == '#') ||
			(ind[0] < 2 && buff[5 * (ind[0] + 2) + ind[1] - 1] == '#'))
				(mtx[1])--;
			if (ind[0] < 3 && ind[1] > 1 && buff[5 * (ind[0] + 1) + ind[1] - 1]
			== '#' && buff[5 * (ind[0] + 1) + ind[1] - 2] == '#')
				(mtx[1])--;
		}
	}
}

static void			fl_tetrsupdate(t_counter *cnt, t_handler *hdl,
					unsigned short *mtx, unsigned short *ind)
{
	(hdl->tetrs[cnt->counter - 1]->shape)
	[4 * (ind[0] - mtx[0]) + ind[1] - mtx[1]] = 1;
	if (hdl->tetrs[cnt->counter - 1]->rows < ind[0] - mtx[0] + 1)
		hdl->tetrs[cnt->counter - 1]->rows = ind[0] - mtx[0] + 1;
	if (hdl->tetrs[cnt->counter - 1]->colls < ind[1] - mtx[1] + 1)
		hdl->tetrs[cnt->counter - 1]->colls = ind[1] - mtx[1] + 1;
	if (hdl->tetrs[cnt->counter - 1]->colls *
	hdl->tetrs[cnt->counter - 1]->rows > 6)
		fl_puterr("error\n");
	(ind[1])++;
}

static void			fl_precheck(char *buff)
{
	int				ind[2];
	int				k;

	ind[0] = -1;
	k = 0;
	while (++ind[0] < 4 && (ind[1] = -1))
		while (++ind[1] < 4)
			if (buff[5 * ind[0] + ind[1]] == '#')
			{
				if (ind[0] != 0 && buff[5 * (ind[0] - 1) + ind[1]] == '#')
					k++;
				if (ind[0] != 3 && buff[5 * (ind[0] + 1) + ind[1]] == '#')
					k++;
				if (ind[1] != 0 && buff[5 * ind[0] + ind[1] - 1] == '#')
					k++;
				if (ind[1] != 3 && buff[5 * ind[0] + ind[1] + 1] == '#')
					k++;
			}
	if (k != 6 && k != 8)
		fl_puterr("error\n");
}

void				fl_tetrsadd(t_counter *cnt, t_handler *hdl, char *buff)
{
	unsigned short	mtx[2];
	unsigned short	ind[2];
	unsigned short	blk_c;

	ind[0] = 0;
	blk_c = 0;
	mtx[1] = 5;
	mtx[0] = 5;
	fl_precheck(buff);
	while (ind[0] < 4 && !(ind[1] = 0))
		while (ind[1] < 5)
			if (buff[5 * ind[0] + ind[1]] == '.' && ind[1] < 4)
				ind[1]++;
			else if (buff[5 * ind[0] + ind[1]] == '#' && ind[1] < 4 && ++blk_c)
			{
				fl_processing(mtx, ind, buff);
				fl_tetrsupdate(cnt, hdl, mtx, ind);
			}
			else if (buff[5 * ind[0] + ind[1]] == '\n' && ind[1]++ == 4)
			{
				if (ind[0]++ == 3 && blk_c != 4)
					fl_puterr("error\n");
			}
			else
				fl_puterr("error\n");
}
