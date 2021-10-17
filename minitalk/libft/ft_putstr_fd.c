#include "ft_libft.h"

size_t	ft_putstr_fd(int fd, const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		ft_putchar_fd(fd, str[i++]);
	return (i);
}
