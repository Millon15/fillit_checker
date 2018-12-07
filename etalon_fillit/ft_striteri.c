/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:02:56 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:02:57 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	while (str && *str && f)
	{
		f(index, str);
		index++;
		str++;
	}
}
