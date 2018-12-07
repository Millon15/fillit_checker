/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:33:20 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 08:40:10 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *ptr, int c, size_t size)
{
	unsigned char	*f_ptr;
	unsigned int	count;

	count = 0;
	f_ptr = (unsigned char *)ptr;
	while (size--)
	{
		if (f_ptr[count] == (unsigned char)c)
			return (f_ptr + count);
		count++;
	}
	return (NULL);
}
