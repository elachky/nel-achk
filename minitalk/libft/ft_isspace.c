#include "ft_libft.h"

int	ft_isspace(int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (i == ' ')
		return (1);
	if (i == '\n')
		return (1);
	if (i == '\t')
		return (1);
	if (i == '\v')
		return (1);
	if (i == '\r')
		return (1);
	if (i == '\f')
		return (1);
	return (0);
}
