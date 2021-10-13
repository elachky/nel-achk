#include "ft_stack.h"

// void print_stack(t_stack *a){
//     while(a)  
//     {
//         printf("%d ", a->data);
//         a = a->next;
//     }
// }

t_stack    *ft_stack_unshift(t_stack **a, int data)
{
    t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return NULL;
    new->data = data;
    new->next = *a;
    (*a) = new;
    return (*a);
}

t_stack    *ft_stack_push(t_stack **a, int data)
{
    t_stack *new;
    t_stack *tmp;
    tmp = *a;
    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return NULL;
    new->data = data;
    new->next = NULL;
    while (1)
    {
        if(tmp->next == NULL)
        {
            tmp->next = new;
            break;
        }
        tmp = tmp->next;
    }
    return (*a);
}