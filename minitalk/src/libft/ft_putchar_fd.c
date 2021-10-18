#include "ft_libft.h"

int	ft_putchar_fd(int fd, int c)
{
	return (write(fd, &c, 1));
}
