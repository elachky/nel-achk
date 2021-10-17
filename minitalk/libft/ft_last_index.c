#include "ft_libft.h"

int ft_last_index(int *arr, int value, int len)
{
    int i;
    int last_index;

    i = 0;
    last_index = 0;
    while(i < len)
    {
        if (arr[i] == value)
            last_index = i;
        i++;
    }
    return (last_index);
}