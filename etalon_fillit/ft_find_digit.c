/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:20:30 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 21:32:17 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_digit(int c, int base)
{
	int	digit;

	digit = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		c = -c;
	while ((c /= base) > 0)
		digit++;
	return (digit);
}
