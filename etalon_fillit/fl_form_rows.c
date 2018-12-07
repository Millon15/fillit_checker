/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_form_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:28:01 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/01 11:11:36 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				fl_create_root(t_counter *count, t_handler *handl)
{
	handl->root = (t_node *)malloc(sizeof(t_node));
	handl->root->h = handl->root;
	handl->root->r = handl->root;
	handl->root->l = handl->root;
	handl->root->u = NULL;
	handl->root->d = NULL;
	handl->root->size = count->size * count->size + count->counter;
	handl->root->sign = NULL;
}

static void				fl_create_header(t_handler *handl, char *head_name)
{
	t_node	*header;

	header = (t_node *)malloc(sizeof(t_node));
	header->h = handl->root;
	header->r = handl->root;
	header->l = handl->root->l;
	(header->r)->l = header;
	(header->l)->r = header;
	header->u = header;
	header->d = header;
	header->size = 0;
	header->sign = ft_strdup(head_name);
	if (ft_atoi(head_name) > 99)
		header->sign[3] = '\0';
	else if (ft_atoi(head_name) > 9)
		header->sign[2] = '\0';
	else
		header->sign[1] = '\0';
}

static void				fl_create_headers(t_counter *count, t_handler *handl,
	unsigned short grid_size)
{
	char			*name;
	unsigned short	i;

	i = 0;
	name = ft_strnew(3);
	name[0] = 'A' - 1;
	name[1] = '\0';
	while (++name[0] < 'A' + count->counter)
		fl_create_header(handl, name);
	free(name);
	while (i < grid_size * grid_size)
	{
		name = ft_strdup(ft_itoa(i));
		fl_create_header(handl, name);
		free(name);
		i++;
	}
}

static unsigned short	*fl_rebuild_row_array(t_tetrimino *tetr,
	t_counter *count, unsigned short r, unsigned short c)
{
	unsigned short		i;
	short				j;
	unsigned short		*shape;

	j = -1;
	shape = (unsigned short *)malloc(sizeof(i) * count->size * count->size);
	while ((unsigned short)++j < r && !(i = 0))
		while (i < count->size)
			shape[i++ + (unsigned short)j * count->size] = 0;
	while ((unsigned short)j - r < tetr->rows && !(i = 0))
	{
		while (i < c)
			shape[i++ + j * count->size] = 0;
		while (i++ - c < tetr->colls)
			shape[i - 1 + j * count->size] =
				tetr->shape[i - 1 - c + (j - r) * 4];
		i--;
		while (i < count->size)
			shape[i++ + j * count->size] = 0;
		j++;
	}
	while (j++ < count->size && !(i = 0))
		while (i < count->size)
			shape[i++ + (j - 1) * count->size] = 0;
	return (shape);
}

void					fl_form_rows(t_counter *count, t_handler *handl)
{
	unsigned short	i;
	unsigned short	c;
	unsigned short	r;
	unsigned short	*shape;

	i = 0;
	fl_create_root(count, handl);
	fl_create_headers(count, handl, count->size);
	while (i < count->counter && !(r = 0))
	{
		while (r + handl->tetrs[i]->rows <= count->size && !(c = 0))
		{
			while (c + handl->tetrs[i]->colls <= count->size)
			{
				shape = fl_rebuild_row_array(handl->tetrs[i], count, r, c++);
				fl_dispose_tetr(count, handl->tetrs[i], handl, shape);
				free(shape);
			}
			r++;
		}
		i++;
	}
}
