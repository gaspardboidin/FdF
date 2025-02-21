/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:08:19 by gaboidin          #+#    #+#             */
/*   Updated: 2025/02/20 15:12:00 by gaboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t			ft_strlen(const char *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strjoin(const char *s1, const char *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *src);
char			*ft_strchr(const char *str, int c);
char			**ft_split(const char *s, char c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *s, int c, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_itoa(int nbr);
int				ft_atoi_base(char *str, char *base);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);
int				ft_parse_and_print(char specifier, va_list args);
int				ft_print_char(char c);
int				ft_print_string(const char *str);
int				ft_print_pointer(void *ptr);
int				ft_print_percent(void);
int				ft_print_decimal(int n);
int				ft_print_unsigned(unsigned int n);
int				ft_print_hex(unsigned int n, int uppercase);
char			*get_next_line(int fd);
int				ft_printf(const char *format, ...);

#endif
