/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:33:33 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 08:33:34 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*f_dest;
	unsigned char	*f_src;

	f_dest = (unsigned char *)dest;
	f_src = (unsigned char *)src;
	while (size--)
		*f_dest++ = *f_src++;
	return (dest);
}
