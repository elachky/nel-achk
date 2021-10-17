#include "ft_utils.h"

int *ft_calloc(int len)
{
    int *arr;
    int i;

    i = 0;
    if (!(arr = (int *)malloc(sizeof(int) * len)))
        return (NULL);
    while (i < len)
        arr[i++] = 0;
    
    return (arr);
}