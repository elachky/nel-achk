/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:23:04 by nel-achk          #+#    #+#             */
/*   Updated: 2021/10/19 15:24:48 by nel-achk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_isspace(int c);
int		ft_atoi(const char *str);
int		ft_putchar_fd(int fd, int c);
int		ft_isdigit(int c);
size_t	ft_putstr_fd(int fd, const char *str);
void	ft_putnbr(int n);
int		ft_isstrdigit(char *s);

#endif
