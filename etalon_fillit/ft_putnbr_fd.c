/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:03:12 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 13:39:40 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == MAX_INT_NUM_NEG)
		ft_putstr_fd(MAX_INT_STR_NEG, fd);
	else
	{
		if (nbr < 0)
		{
			ft_putchar_fd((char)45, fd);
			nbr *= -1;
		}
		if (nbr > 9)
			ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((char)((nbr % 10) + 48), fd);
	}
}
