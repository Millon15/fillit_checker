/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <osyrotiu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:49:02 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 22:06:49 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0
# define MAX_INT_NUM_POS 2147483648
# define MAX_INT_STR_POS "2147483648"
# define MAX_INT_NUM_NEG -2147483648
# define MAX_INT_STR_NEG "-2147483648"

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *node));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *list, void (*f)(t_list *node));

void				*ft_memset(void *ptr, int byte, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memccpy(void *dest,
					const void *src, int c, size_t size);
void				*ft_memmove(void *dest, void *src, size_t size);
void				*ft_memchr(const void *ptr, int c, size_t size);
void				*ft_memalloc(size_t size);

void				ft_striteri(char *str, void (*f)(unsigned int, char *));
void				ft_striter(char *str, void (*f)(char *));
void				ft_bzero(void *ptr, size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strrev(char *str);
void				ft_strclr(char *str);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int nbr, int fd);

int					ft_memcmp(const void *src1, const void *src2, size_t size);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strequ(char const *str1, char const *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t size);
int					ft_strnequ(char const *str1, char const *str2, size_t size);
int					ft_find_digit(int c, int base);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_abs(int nbr);

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, char *src, size_t size);

char				*ft_itoa(int nbr);
char				*ft_itoa_base(int nbr, int base);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t size);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *str1, const char *str2);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
					const char *little, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *str);
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));

char				**ft_strsplit(char const *str, char c);

#endif
