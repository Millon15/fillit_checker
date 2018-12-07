/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:32:27 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 17:16:07 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strrev(char *str)
{
	char	*start;
	char	*end;

	if (str)
	{
		start = str;
		end = str;
		while (*(end + 1))
			end++;
		while (end > start)
		{
			*end ^= *start;
			*start ^= *end;
			*end ^= *start;
			start++;
			end--;
		}
	}
}
