/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:07:19 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:07:25 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *str,
					char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*new;

	index = 0;
	if (!str || !f || !(new = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (*str && str)
	{
		new[index] = f(index, *str);
		index++;
		str++;
	}
	new[index] = '\0';
	return (new);
}
