/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blk_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:33:00 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/30 16:42:25 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

char	*ft_blk_rot(char *blk, int rot)
{
	char	*ret;
	int		ret_i;
	int		blk_i;
	int		eof;
	int		blk_init;

	ret_i = -1;
	eof = 1;
	ret = (char *)malloc(sizeof(char) * 20);
	if (rot == 0)
		return (blk);
	else
	{
		if (rot == 1)
			blk_init = 15;
		if (rot == 2)
			blk_init = 18;
		if (rot == 3)
			blk_init = 3;
		blk_i = blk_init;
		while (++ret_i < 20)
		{
			if (ret_i == 4 || ret_i == 9 || ret_i == 14 || ret_i == 19)
			{
				ret[ret_i] = '\n';
				if (rot == 1)
					blk_i = blk_init + eof;
				if (rot == 2)
					blk_i--;
				if (rot == 3)
					blk_i = blk_init - eof;
				eof++;
			}
			else
			{
				ret[ret_i] = blk[blk_i];
				if (rot == 1)
					blk_i -= 5;
				if (rot == 2)
					blk_i--;
				if (rot == 3)
					blk_i +=5;
			}
		}
		return (ret);
	}
}
