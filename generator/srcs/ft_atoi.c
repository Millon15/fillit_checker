/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 09:03:12 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/03 10:12:03 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_bool	ft_isop(char c)
{
	return ((c == '-' || c == '+') ? TRUE : FALSE);
}

int				ft_atoi(const char *str)
{
	int		ret;
	int		index;
	int		isneg;

	ret = 0;
	index = 0;
	isneg = 1;
	while (ft_isspace(str[index]) && str[index])
		index++;
	if (!ft_isdigit((int)str[index]) && !ft_isop(str[index]))
		return (FALSE);
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		isneg = -1;
		index++;
	}
	while (ft_isdigit((int)str[index]))
	{
		ret = (ret * 10) + (str[index] - '0');
		index++;
	}
	return (ret * isneg);
}
