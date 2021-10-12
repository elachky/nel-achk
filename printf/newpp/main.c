#include <ft_printf.h>
#include <stdio.h>

#define H "[\n%% %*p %-5s %%%% %016X  %5c %-10.9u&& %*xzzzzz %   % %]\n", -9, INT_MAX, NULL, INT_MAX, 'a', 12345678, 65, 654

int main()
{
    int i;
    int j;

    i = ft_printf(H);
    j = printf(H);
    printf("%d, %d",i, j);
    return (0);
}
