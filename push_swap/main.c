#include "push_swap.h"

int main(int argc, char **argv)
{
    int *stack;
    t_stack *a;
    t_stack *b;

    // if (!stack)
    // {
    //     write(2, "memory problem\n", 15);
    //     return 1;
    // }
    if (argc > 1)
    {
        if (check_args(argc, argv) == 0)
        {
            // *a = (t_stack *)malloc(sizeof(t_stack) * argc);
            // *b = (t_stack *)malloc(sizeof(t_stack) * argc);
            // if (!(*a) || !(*b))
            // {
            //     write(2, "memory problem\n", 15);
            //     return 1;
            // }
            if ((stack = tokenize(argc, argv)) == NULL)
                return 1;
            
            // set_on_stack(&a, &b, &stack);
            // free(stack);
            //sort logic
        }
    }

    printf("stack a : \n");
    for (int i = 0; i < argc - 1; i++)
        printf("%d\n", stack[i]);
    return 0;
}