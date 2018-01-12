/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:00:29 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/26 18:50:33 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

# define NB_OPT 6

typedef int	(*t_f)(va_list);

size_t		ft_strlen(const char *str);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
char		*ft_strnew(size_t size);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
char		*ft_uitoa(unsigned int n);

int			ft_putchar_i(char c);
int			ft_putstr_i(char *str);

int			ft_s(va_list ap);
int			ft_c(va_list ap);
int			ft_d(va_list ap);
int			ft_u(va_list ap);
int			ft_o(va_list ap);

int			ft_printf(const char *format, ...);

#endif
