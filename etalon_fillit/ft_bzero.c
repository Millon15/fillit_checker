/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:31:31 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 08:31:52 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *ptr, size_t size)
{
	unsigned char	*f_ptr;

	f_ptr = (unsigned char *)ptr;
	while (size--)
		f_ptr[size] = (unsigned char)'\0';
}
