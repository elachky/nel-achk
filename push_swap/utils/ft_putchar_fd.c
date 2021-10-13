#include "ft_utils.h"

int	ft_putchar_fd(int fd, int c)
{
	return (write(fd, &c, 1));
}
