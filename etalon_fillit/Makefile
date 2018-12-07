# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osyrotiu <osyrotiu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 17:56:40 by osyrotiu          #+#    #+#              #
#    Updated: 2018/11/01 18:16:56 by osyrotiu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= fillit
FLAGS 			= -Wall -Wextra -Werror
SRCS_NAME 		= fillit.c \
					fl_solutionloop.c \
					fl_cover.c \
					fl_find_solution.c \
					fl_pop.c \
					fl_push.c \
					fl_uncover.c \
					fl_create_link.c \
					fl_delete_link.c \
					fl_dispose_tetr.c \
					fl_form_rows.c \
					fl_gettetrs.c \
					fl_free_soll.c \
					fl_free_table.c \
					fl_tetrsfree.c \
					fl_tetrsrealloc.c \
					fl_tetrsadd.c \
					fl_print_solution.c \
					fl_puterr.c \
					ft_atoi.c\
				  	ft_abs.c\
				  	ft_bzero.c\
				  	ft_isspace.c\
				  	ft_isalnum.c\
				  	ft_isalpha.c\
				  	ft_isascii.c\
				  	ft_isdigit.c\
				  	ft_isprint.c\
				  	ft_find_digit.c\
				  	ft_memccpy.c\
				  	ft_memchr.c\
				  	ft_memcmp.c\
				  	ft_memcpy.c\
				  	ft_memmove.c\
				  	ft_memset.c\
				  	ft_strcat.c\
				  	ft_strchr.c\
				  	ft_strcmp.c\
				  	ft_strcpy.c\
				  	ft_strdup.c\
				  	ft_strlcat.c\
				  	ft_strlen.c\
				  	ft_strncat.c\
				  	ft_strncmp.c\
				  	ft_strncpy.c\
				  	ft_strrchr.c\
				  	ft_strstr.c\
				  	ft_strnstr.c\
				  	ft_tolower.c\
				  	ft_toupper.c\
				  	ft_memalloc.c\
				  	ft_memdel.c\
				  	ft_strrev.c\
				  	ft_strnew.c\
				  	ft_strdel.c\
				  	ft_strclr.c\
				  	ft_striter.c\
				  	ft_striteri.c\
				  	ft_strmap.c\
				  	ft_strmapi.c\
				  	ft_strequ.c\
				  	ft_strnequ.c\
					ft_strsub.c\
				 	ft_strjoin.c\
				 	ft_strtrim.c\
				  	ft_strsplit.c\
				  	ft_itoa.c\
				  	ft_itoa_base.c\
				  	ft_putchar.c\
				  	ft_putstr.c\
				  	ft_putendl.c\
				  	ft_putnbr.c\
				  	ft_putchar_fd.c\
				  	ft_putstr_fd.c\
					ft_putnbr_fd.c\
					ft_putendl_fd.c\
				 	ft_lstnew.c\
				  	ft_lstdelone.c\
				  	ft_lstdel.c\
				  	ft_lstadd.c\
				  	ft_lstiter.c\
				  	ft_lstmap.c

CC				= gcc
INC_PATH 		= ./
OBJ_PATH		= ./objects/

SRCS 			= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ 			= $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all				: $(NAME)

$(NAME)			: $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o 	: $(SRCS_PATH)%.c
	@mkdir -p ./objects
	@$(CC) -c $(FLAGS) -I $(INC_PATH) $< -o $@

clean			:
	@/bin/rm -rf $(OBJ_PATH)

fclean			: clean
	@/bin/rm -rf $(NAME)

re				: fclean all

.PHONY			: all, clean, fclean, re
