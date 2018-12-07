/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:59:31 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 09:12:40 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int nbr)
{
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
		return (1 + ft_nlen(-nbr));
	if (nbr /= 10)
		return (1 + ft_nlen(nbr));
	return (1);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len;

	len = ft_nlen(nbr);
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (NULL);
	if (nbr == -2147483648)
		str = ft_strdup("-2147483648\0");
	else
	{
		str[len] = '\0';
		if (nbr < 0 && (str[0] = '-'))
			nbr = -nbr;
		while (--len >= 0 && !str[len])
		{
			str[len] = '0' + nbr % 10;
			nbr /= 10;
		}
	}
	return (str);
}
