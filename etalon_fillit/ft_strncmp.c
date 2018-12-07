/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:10:43 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/25 15:10:44 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *str1, const char *str2,
					size_t size)
{
	unsigned int	count;

	count = 0;
	if (!size)
		return (0);
	else
	{
		while (str2[count] && (count < size - 1) &&
				(str1[count] == str2[count]))
			count++;
		return ((unsigned char)str1[count] - (unsigned char)str2[count]);
	}
}
