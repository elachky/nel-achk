#include "../headers/push_swap.h"

static int check_duplicates(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {

            if (strcmp(argv[i], argv[j]) == 0)
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

static int check_is_number(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

static int check_negatif_numbers(int argc, char **argv)
{
    int i;

    i = 0;
    while (++i < argc)
        if(argv[i][0] == '-')
            return 1;
    return 0;
}

int check_args(int argc, char **argv)
{
    if (check_duplicates(argc, argv) == 1)
    {
        write(2, "error: duplicate numbers\n", 25);
        return 1;
    }
    if (check_negatif_numbers(argc, argv) == 1)
    {
        write(2, "error: negatif number\n", 23);
        return 1;
    }
    if (check_is_number(argc, argv) == 1)
    {
        write(2, "error: non digit values\n", 25);
        return 1;
    }
    return 0;
}