#include "ft_libft.h"

int ft_max_arr(int *arr, int len)
{
    int i;
    int max;
    
    max = 0;
    i = 0;
    while (i < len)
    {    
        if (max < arr[i])
            max = arr[i];
        i++;
    }
    return (max);
}