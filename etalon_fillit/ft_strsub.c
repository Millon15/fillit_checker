/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:02:27 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 17:10:38 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *str, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*res;

	index = 0;
	if (!str || (start > ft_strlen(str)) || !(res = ft_strnew(len)))
		return (NULL);
	while (index < len && str[start])
	{
		res[index] = str[start];
		start++;
		index++;
	}
	res[index] = '\0';
	return (res);
}
