/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:17:48 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 17:42:56 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "ft_printf.h"

typedef unsigned char	t_byte;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
void				ft_strclr(char *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strupcase(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, int n, int m);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(char c);
void				ft_putnchar(char c, int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_lst_size(t_list *list);
t_list				*ft_lst_at(t_list *lst, int nb);
void				ft_lst_insert(t_list **list, t_list *elem, int pos);
void				ft_lst_swap_cnt(t_list *elem1, t_list *elem2);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstfree_cnt(void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_strsplit_lst(char const *s, char c);
void				ft_putnbr_base(int n, char *base);
void				ft_lstadd_back(t_list *alst, t_list *new);
int					ft_isspace(char c);
char				**ft_split_whitespace(char const *s);
int					get_next_line(const int fd, char **line);
void				*ft_print_memory(const void *ptr, size_t size);
int					ft_abs(int n);
void				ft_print_bits(unsigned char octet);
void				ft_putwchar(wint_t c);
void				ft_putwchar_fd(wint_t c, int fd);
void				ft_putwstr_fd(wint_t *str, int fd);
void				ft_putwstr(wint_t *str);
char				*ft_itoa_base(intmax_t n, int base);
int					ft_max(int a, int b);
int					nb_size(intmax_t nb);
void				ft_strtab_free(char **str);
void				*ft_realloc(void *ptr, size_t old, size_t new);
char				**ft_strtab_dup(char **str);

#endif
