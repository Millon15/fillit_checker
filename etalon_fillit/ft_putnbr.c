/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:03:04 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 13:40:32 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr == MAX_INT_NUM_NEG)
		ft_putstr(MAX_INT_STR_NEG);
	else
	{
		if (nbr < 0)
		{
			ft_putchar((char)45);
			nbr *= -1;
		}
		if (nbr > 9)
			ft_putnbr(nbr / 10);
		ft_putchar((char)((nbr % 10) + 48));
	}
}
