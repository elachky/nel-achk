#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int     ft_isspace(int c);
int		ft_atoi(const char *str);
int		ft_putchar_fd(int fd, int c);
int		ft_isdigit(int c);
size_t	ft_putstr_fd(int fd, const char *str);
void	ft_putnbr(int n);
int     ft_isstrdigit(char *s);

#endif