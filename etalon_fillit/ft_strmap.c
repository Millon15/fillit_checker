/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:05:12 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:05:22 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *str, char (*f)(char))
{
	unsigned int	index;
	char			*new;

	index = 0;
	if (!str || !f || !(new = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (*str && str && f)
	{
		new[index] = f(*str);
		index++;
		str++;
	}
	new[index] = '\0';
	return (new);
}
