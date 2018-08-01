/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/04/12 19:39:47 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

short			ft_atos(const char *str);
void			error();
int				sml(int a, int b);
int				big(int a, int b);
void			ft_putwcharstr(wchar_t *str, int *printed, size_t count);
void			ft_write_count(const void *buf, size_t c, int *printed, int w);
size_t			ft_wcslen(const void *wc);
size_t			ft_voidstrlen(const void *str);
char			*ft_ntchar(int n, char c);
char			*ft_skip_digits(char **str);
int				ft_indexof(char *str, char c);
char			*ft_lltoa(long long value);
char			*ft_ulltoa_base(unsigned long long value, int base, int caps);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strrchr(const char *d, int c);
char			*ft_strchr(const char *d, int c);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
int				ft_isascii(int c);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strcat(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strncat(char *dest, const char *src, size_t nb);
char			*ft_strstr(const char *str, const char *to_find);
void			ft_bzero(void *ptr, size_t num);
char			*ft_strtrim(char const *s);
void			*ft_memcpy(void *d, const void *s, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *d, int c, size_t n);
int				ft_isalpha(int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
char			**ft_strsplit(char const *s, char c);
int				ft_memcmp(const void *a, const void *b, size_t n);
char			*ft_itoa(int n);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strncmp(const char *a, const char *b, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
#endif
