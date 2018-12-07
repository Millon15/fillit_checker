/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:46:11 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 21:38:33 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*whitespaces(char *str)
{
	if (!(str = (char *)malloc(2)))
		return (NULL);
	*str = 48;
	*(str + 1) = '\0';
	return (str);
}

static char		*magic(char *str, long int num, int neg, int base)
{
	int			index;
	int			rem;

	index = 0;
	if (!(str = (char *)malloc((ft_find_digit(num, 10) + neg) * sizeof(char))))
		return (NULL);
	while (num)
	{
		rem = num % base;
		str[index++] = (rem > 9) ? (rem - 10) + 97 : rem + 48;
		num /= base;
	}
	if (neg == 3)
		str[index++] = 45;
	str[index] = '\0';
	return (str);
}

char			*ft_itoa_base(int nbr, int base)
{
	long int	num;
	short		neg;
	char		*str;

	num = nbr;
	str = NULL;
	if (!num)
		return (whitespaces(str));
	neg = 2;
	if (num < 0 && base == 10)
	{
		neg = 3;
		num = -num;
	}
	if (!(str = magic(str, num, neg, base)))
		return (NULL);
	ft_strrev(str);
	return (str);
}
