#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_putchar_fd(int fd, int c);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(int c);
size_t	ft_putstr_fd(int fd, const char *str);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *str);
int		get_next_line(char **line);
void	ft_putnbr(int n);
int 	*ft_calloc(int n);

#endif