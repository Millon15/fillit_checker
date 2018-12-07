/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:37:45 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:32:49 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned int	index;
	unsigned char	*f_dest;
	unsigned char	*f_src;

	index = 0;
	f_src = (unsigned char *)src;
	f_dest = (unsigned char *)dest;
	while (index < size)
	{
		f_dest[index] = f_src[index];
		if (f_src[index] == (unsigned char)c)
			return (f_dest + index + 1);
		index++;
	}
	return (NULL);
}
