/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:10:16 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:10:17 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *dest, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	index;
	unsigned int	length;

	count = 0;
	index = count;
	length = ft_strlen(dest);
	while (src[index] && size--)
	{
		dest[length + count] = src[index];
		count++;
		index++;
	}
	dest[length + count] = '\0';
	return (dest);
}
