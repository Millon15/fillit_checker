/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:22:02 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/03 10:30:45 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define BUFFER 1024

typedef int	t_bool;

# define TRUE 1
# define FALSE 0

char	*ft_blk_rot(char *blk, int rot);
int		ft_rand(int min, int max);
int		ft_atoi(const char *str);
t_bool	ft_isspace(char c);
t_bool	ft_isdigit(int c);

#endif
