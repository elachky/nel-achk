#include "ft_libft.h"

int ft_isstrdigit(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        if (!ft_isdigit(s[i++]))
            return (0);
    return (1);
}