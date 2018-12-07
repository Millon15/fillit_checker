/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:05:43 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:05:50 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *str1, const char *str2)
{
	if (str1 != NULL && str2 != NULL)
		return (ft_strcmp(str1, str2) ? 0 : 1);
	else
		return (0);
}
