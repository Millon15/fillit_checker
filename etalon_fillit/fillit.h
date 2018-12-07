/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:39:34 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/11/01 11:33:12 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define MODEL_WORLD_SIZE 16

typedef struct s_tetrimino	t_tetrimino;
typedef struct s_handler	t_handler;
typedef struct s_counter	t_counter;
typedef struct s_node		t_node;

struct						s_tetrimino
{
	unsigned short			shape[MODEL_WORLD_SIZE];
	unsigned short			colls;
	unsigned short			rows;
	char					sign;
};

struct						s_node
{
	char					*sign;
	int						size;
	t_node					*h;
	t_node					*l;
	t_node					*r;
	t_node					*u;
	t_node					*d;
};

struct						s_counter
{
	unsigned short			counter;
	unsigned short			nodes;
	unsigned short			size;
};

struct						s_handler
{
	t_tetrimino				**tetrs;
	t_node					**soll;
	t_node					*root;
};

void						fl_solutionloop(int argc, char **argv);
void						fl_puterr(char *err);
void						fl_free_table(t_handler *handl);
void						fl_form_rows(t_counter *count,
							t_handler *handl);
void						fl_tetrsfree(t_handler *handl,
							t_counter *count);
void						fl_dispose_tetr(t_counter *count,
							t_tetrimino *tetr,
							t_handler *handl, unsigned short *shape);
void						fl_tetrsrealloc(t_handler *handl,
							t_counter *count);
void						fl_get_tetrs(t_handler *handl,
							t_counter *count, char *file);
void						fl_cover(t_handler *handl, t_node *header);
void						fl_uncover(t_handler *handl, t_node *header);
void						fl_free_soll(t_counter *count,
							t_handler *handl);
void						fl_print_solution(t_counter *count,
							t_handler *handl);
void						fl_push(t_counter *count,
							t_handler *handl, t_node *row);
void						fl_find_solution(t_counter *count,
							t_handler *handl, t_node *header);
void						fl_tetrsadd(t_counter *cnt, t_handler *handl,
							char *buff);
t_node						*fl_create_link(t_node *last, t_node *header,
							char *link_name);
t_node						*fl_pop(t_counter *count, t_handler *handl);
t_node						*fl_delete_link(t_handler *handl, t_node *link);

#endif
