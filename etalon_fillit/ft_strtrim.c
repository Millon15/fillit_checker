/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:11:19 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:12:43 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str)
{
	int		length;
	int		index;
	char	*result;

	if (!str || !(result = ft_strdup(str)))
		return (NULL);
	index = 0;
	while (result[index] && ft_isspace(result[index]))
		index++;
	length = ft_strlen(str) - 1;
	while (length > 0)
	{
		if (ft_isspace(result[length]))
			length--;
		else
		{
			result[length + 1] = '\0';
			break ;
		}
	}
	return (ft_strdup(result + index));
}
