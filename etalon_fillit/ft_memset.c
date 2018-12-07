/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:42:25 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 08:55:46 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int byte, size_t size)
{
	unsigned char	*f_ptr;

	f_ptr = (unsigned char *)ptr;
	while (size--)
		f_ptr[size] = (unsigned char)byte;
	return (ptr);
}
