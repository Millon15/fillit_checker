/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:10:34 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:10:35 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *str1, char const *str2, size_t size)
{
	if (str1 != NULL && str2 != NULL)
		return (ft_strncmp(str1, str2, size) ? 0 : 1);
	else
		return (0);
}
