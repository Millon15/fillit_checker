/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:45:23 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 08:55:22 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, void *src, size_t size)
{
	unsigned char	*f_dest;
	unsigned char	*f_src;
	unsigned int	index;

	f_dest = (unsigned char *)dest;
	f_src = (unsigned char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, size));
	else
	{
		index = size;
		while (index-- > 0)
			f_dest[index] = f_src[index];
	}
	return (dest);
}
