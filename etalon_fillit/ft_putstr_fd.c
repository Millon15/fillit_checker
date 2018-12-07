/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:03:32 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 12:42:37 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_fd(char const *src, int fd)
{
	unsigned int	index;

	index = 0;
	while (src && src[index] && (fd > -1))
		ft_putchar_fd(src[index++], fd);
}
