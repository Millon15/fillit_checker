/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:30:18 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 14:06:31 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	counter(const char *str, char c)
{
	unsigned int	counter;
	unsigned int	indexing;

	indexing = 0;
	counter = 0;
	while (*str)
	{
		if (indexing == TRUE && *str == c)
			indexing = FALSE;
		if (indexing == FALSE && *str != c)
		{
			indexing = TRUE;
			counter++;
		}
		str++;
	}
	return (counter);
}

static unsigned int	length(const char *str, char c)
{
	unsigned int	len;

	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

char				**ft_strsplit(char const *str, char c)
{
	char			**table;
	int				count;
	int				index;

	if (!str)
		return (NULL);
	index = 0;
	count = counter(str, c);
	if (!(table = (char **)malloc(sizeof(*table) * (count + 1))))
		return (NULL);
	while (count--)
	{
		while (*str == c && *str)
			str++;
		table[index] = ft_strsub(str, 0, length(str, c));
		if (!table[index])
			return (NULL);
		str = str + length(str, c);
		index++;
	}
	table[index] = NULL;
	return (table);
}
