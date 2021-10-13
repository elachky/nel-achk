#include "push_swap.h"

static int *dup_elements(int argc, char **argv)
{
    int     *res;
    long    temp;
    int     i;

    i = 0;
    if (!(res = (int *)malloc(sizeof(int) * argc)))
        return NULL;
    while (i < argc - 1)
    {
        temp = ft_atol(argv[i + 1]);
        if (temp > P_MAX_INT || temp < P_MIN_INT)
        {
            ft_putstr_fd(2, "Error out of range\n");
            exit(1);
        }
        res[i] = (int)temp;
        i++;
    }
    return res;
}

static void is_sorted(int argc, int *list){
    int i;

    i = 0;
    while (i < argc - 1)
    {
        if (list[i] < list[i + 1])
            return ;
        i++;
    }
    exit(0);
}

static int is_rev_sorted(int argc, int *list){
    int i;

    i = 0;
    while (i < argc - 1)
    {
        if (list[i] > list[i + 1])
            return 1;
        i++;
    }
    return (0);
}

static void sort(int argc, int **list)
{
    int i;
    int j;
    int trash;
    int *temp;

    temp = *list;
    i = 0;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if (temp[i] > temp[j])
            {
                trash = temp[i];
                temp[i] = temp[j];
                temp[j] = trash;
            }
            j++;
        }
        i++;
    }
}

void    label_with_index(int length, int *sorted, int **list){
    int left;
    int right;
    int mid;
    int *a;
    int i;

    a = *list;
    i = 0;
    while (i <= length)
    {
        left = 0;
        right = length - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (a[i] == sorted[mid])
            {
                a[i] = mid;
                break;
            }
            else if (a[i] < sorted[mid])
                right = mid - 1;
            else if (a[i] > sorted[mid])
                left = mid + 1;
        }
        i++;
    }
}

int *tokenize(int argc, char **argv)
{
    int *temp;
    int *a;
    int i;

    i = 0;
    a = (int *)malloc(sizeof(int) * argc);
    temp = dup_elements(argc, argv);
    while (i < argc - 1)
    {
        a[i] = temp[i];
        i++;
    }
    is_sorted(argc - 1, temp);
    if (is_rev_sorted(argc - 1, temp) == 0)
    {
        //reverse the stack argc - 1 time and exit 0 
        printf("is_rev_sorted\n");
    }
    sort(argc - 1, &temp);
    label_with_index(argc - 1, temp, &a);
    free(temp);
    return (a);
}