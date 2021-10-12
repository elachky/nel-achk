/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 01:44:26 by nel-achk          #+#    #+#             */
/*   Updated: 2020/11/11 10:26:30 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef	struct	s_specification
{
	int	pad_zero;
	int	pad_moins;
	int	width;
	int	precision;
	int min_width;
}				t_specif;

void			put(char c, int i);
int				ft_max(int i, int j);
char			*ft_toupper_str(char *str);

int				ft_isalpha(int c);
int				ft_isalnum(int c);
size_t			ft_strlen(const char *c);
int				ft_isdigit(int c);
int				ft_toupper(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_itoa_unsign(unsigned int n);
char			*ft_itoa_hexa(long unsigned int n);

void			test_pad(char *fmt, t_specif *flags, int *j);
void			test_width(char *fmt, t_specif *flags, va_list args, int *j);
void			test_precision(char *fmt, t_specif *flags, va_list args, \
				int *j);

int				print_int(char **str, t_specif *flags, va_list args, char c);
int				print_prst(t_specif *flags, int *j);
int				print_char(char c, t_specif *flags, int *j);
int				print_hexa(char **str, t_specif *flags, char c);
int				print_str(char **str, t_specif *flags, va_list args, int *j);

int				prog(char *fmt, va_list args);
int				ft_printf(const char *fmt, ...);

#endif
