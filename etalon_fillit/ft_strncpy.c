/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:10:25 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:10:27 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, const char *src,
					size_t size)
{
	char			*f_dest;

	f_dest = dest;
	while (size--)
		*f_dest++ = *src ? *src++ : '\0';
	return (dest);
}
