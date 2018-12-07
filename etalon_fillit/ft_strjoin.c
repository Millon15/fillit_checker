/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:06:09 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 15:23:16 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *str1, char const *str2)
{
	unsigned int	first_len;
	unsigned int	second_len;
	char			*res;

	first_len = 0;
	second_len = 0;
	if (!str1 || !str2)
		return (NULL);
	if (str1 && *str1)
		first_len = ft_strlen(str1);
	if (str2 && *str2)
		second_len = ft_strlen(str2);
	if (!(res = (char *)malloc(first_len + second_len + 1)))
		return (NULL);
	ft_strcpy(res, str1);
	ft_strcat(res, str2);
	return (res);
}
