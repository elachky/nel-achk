#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmpa; //only for display
    t_stack *tmpb; //only for display

    a = NULL;
    b = NULL;
    if (argc > 1)
    {
        if (check_args(argc, argv) == 0)
        {
            set_on_stack(&a, argc, argv);
                
            //sort logic
            push_swap_sort(&a, /*&b,*/ argc - 1);
        }
    }
    // ft_stack_pushto(&a, &b);
    // ft_stack_pushto(&a, &b);
    // ft_stack_pushto(&a, &b);
    // ft_stack_pushto(&a, &b);
    tmpa = a;
    tmpb = b;



    printf("length a : %d\n",ft_stack_len(a));
    while (tmpa){
        printf("%d ", tmpa->data);
        tmpa = tmpa->next;
    }
    printf("\nlength b : %d\n",ft_stack_len(b));
    while (tmpb){
        printf("%d ", tmpb->data);
        tmpb = tmpb->next;
    }

    ft_stack_destroy(&a); // to remove to the end of block if check_args 
    ft_stack_destroy(&b); // this one too
    return 0;
}