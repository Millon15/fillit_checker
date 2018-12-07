/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:11:44 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:11:44 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *big, const char *little)
{
	unsigned int	length;
	unsigned int	count;

	if (!(*little) || !little)
		return ((char *)big);
	count = 0;
	length = ft_strlen(little);
	while (big[count])
	{
		if (!(ft_strncmp(big + count, little, length)))
			return ((char *)(big + count));
		count++;
	}
	return (NULL);
}
