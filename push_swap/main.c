#include "push_swap.h"

int main(int argc, char **argv)
{
    int *stack;
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
            if ((stack = tokenize(argc, argv)) == NULL)
                return 1;
            set_on_stack(&a, stack, argc - 1);
            free(stack);
            //sort logic
        }
    }
    ft_stack_pushto(&a, &b);
    ft_stack_pushto(&a, &b);
    ft_stack_pushto(&a, &b);
    ft_stack_pushto(&a, &b);
    tmpa = a;
    tmpb = b;



    while (tmpa){
        printf("%d ", tmpa->data);
        tmpa = tmpa->next;
    }
    printf("\n\n");
    while (tmpb){
        printf("%d ", tmpb->data);
        tmpb = tmpb->next;
    }

    ft_stack_destroy(&a);
    ft_stack_destroy(&b);
    return 0;
}