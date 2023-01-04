#include<unistd.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

int main(int argc, char **argv)
{
    t_ps_list  *a;
    t_ps_list  *b;

    a = NULL;
    b = NULL;
    if (argc > 1 && argc - 1 <= UINT_MAX)
    {
        if (loadlist(argc, argv, &a) == 0)
        {
            write(2, "error\n", 6);
            return (1);
        }
        if (issorted(a))
            return (0);
        printlist(a);
    }
    return (0);
}