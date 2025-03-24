/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:28:22 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/19 08:45:32 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*ft_itoa(int n);
char	**ft_split(char *str, char c);
char	*ft_strchr(const char *str, int i);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *hstr, const char *nstr, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_substr(const char *str, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_tolower(int i);
int		ft_toupper(int i);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	*ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int i, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
int		ft_printf(const char *format, ...);
int		ft_printf_aux(const char *format, va_list args);
int		ft_printf_c(char c);
int		ft_printf_dec(int n);
char	*ft_itoa(int n);
int		ft_printf_p(void *ptr);
int		ft_sprintf(unsigned long adress);
int		ft_count_digit(int dec);
int		ft_printf_s(char const *ptr);
int		ft_printf_u(unsigned int n);
char	*ft_itoa_uns(unsigned int dec);
int		ft_count_digit_uns(unsigned int n);
size_t	ft_strlen(const char *str);
int		ft_printf_x(unsigned long c);
int		ft_printf_xup(unsigned long c);
int		ft_count_hex_digits(unsigned long hex);
char	*ft_itoa_hex_l(unsigned long hex);
char	*ft_itoa_hex_u(unsigned long hex);
void	ft_sprintf_write(char *buffer, int i);
char	*ft_strdup(const char *str);
int		ft_putstr(char *buffer);

#endif