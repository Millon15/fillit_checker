/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:01:38 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:01:39 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*alloc;

	if (!size || !(alloc = (void *)malloc(size)))
		return (NULL);
	else
	{
		ft_bzero(alloc, size);
		return (alloc);
	}
}
