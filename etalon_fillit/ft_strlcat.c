/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:09:42 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:09:43 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	index;
	unsigned int	dest_len;
	unsigned int	src_len;

	index = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (!size)
		return (dest_len);
	while (*src && (index + dest_len < size - 1))
	{
		dest[index + dest_len] = *src++;
		index++;
	}
	dest[index + dest_len] = '\0';
	return (src_len += dest_len < size ? dest_len : size);
}
