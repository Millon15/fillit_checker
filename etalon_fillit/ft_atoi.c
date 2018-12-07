/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:37:03 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 20:44:47 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	unsigned int	index;
	size_t			res;
	int				signum;

	res = 0;
	index = 0;
	signum = 1;
	while ((nptr[index] > -1 && nptr[index] < 21) || ft_isspace(nptr[index]))
		index++;
	if (nptr[index] == 45)
		signum = -1;
	if (nptr[index] == 45 || nptr[index] == 43)
		index++;
	while (nptr[index] > 47 && nptr[index] < 58)
	{
		res = res * 10 + nptr[index++] - 48;
		if (res > 9223372036854775807U && signum == 1)
			return (-1);
		if (res > 9223372036854775808U && signum == -1)
			return (0);
	}
	return (res * signum);
}
