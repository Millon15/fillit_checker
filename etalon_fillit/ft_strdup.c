/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:04:14 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:04:29 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *str)
{
	unsigned int	count;
	char			*dest;

	count = 0;
	while (str[count])
		count++;
	dest = (char *)malloc((size_t)count + 1);
	if (!dest)
		return (NULL);
	dest[count] = '\0';
	while (count--)
		dest[count] = str[count];
	return (dest);
}
