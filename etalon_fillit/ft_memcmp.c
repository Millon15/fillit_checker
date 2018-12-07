/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:34:05 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 08:51:24 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *src1, const void *src2,
					size_t size)
{
	unsigned char	*f_src1;
	unsigned char	*f_src2;
	unsigned int	count;

	count = 0;
	f_src1 = (unsigned char *)src1;
	f_src2 = (unsigned char *)src2;
	while (count < size)
	{
		if (f_src1[count] - f_src2[count])
			return (f_src1[count] - f_src2[count]);
		count++;
	}
	return (0);
}
