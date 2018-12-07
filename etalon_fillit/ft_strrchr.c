/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:11:00 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:11:06 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int c)
{
	unsigned int	count;

	count = ft_strlen(str) + 1;
	while (count-- > 0)
	{
		if (str[count] == (char)c)
			return ((char *)str + (char)count);
	}
	return (NULL);
}
