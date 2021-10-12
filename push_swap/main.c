#include "push_swap.h"

int main(int argc, char **argv)
{
    int **stacks;

    stacks = (int **)malloc(sizeof(int *) * 2);
    if (!stacks)
    {
        write(2, "memory problem\n", 15);
        return 1;
    }
    if (argc == 1)
        write(2, "error args\n", 11);
    else
    {
        if (check_args(argc, argv, &stacks) == 0)
        {
            tokenize(argc, argv, &stacks);
            //sort logic
        }
    }

    printf("stack a : \n");
    for (int i = 0; i < argc - 1; i++)
        printf("%d\n", stacks[0][i]);
    return 0;
}