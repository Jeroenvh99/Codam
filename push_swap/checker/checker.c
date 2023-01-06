#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<limits.h>
#include"../push_swap.h"

int getfunctionindex(char *instr)
{
    if (ft_strncmp(instr, "sa"))
        return (0);
    else if (ft_strncmp(instr, "sb"))
        return (1);
    else if (ft_strncmp(instr, "ss"))
        return (2);
    else if (ft_strncmp(instr, "pa"))
        return (3);
    else if (ft_strncmp(instr, "pb"))
        return (4);
    else if (ft_strncmp(instr, "ra"))
        return (5);
    else if (ft_strncmp(instr, "rb"))
        return (6);
    else if (ft_strncmp(instr, "rr"))
        return (7);
    else if (ft_strncmp(instr, "rra"))
        return (8);
    else if (ft_strncmp(instr, "rrb"))
        return (9);
    else if (ft_strncmp(instr, "rrr"))
        return (10);
    return (-1);
}

int doubleinstr(void (*instructions[]) (t_ps_list *, t_ps_list *), int i,
    t_ps_list *a, t_ps_list *b)
{
    if (i == 2)
    {
        instructions[0](a, b);
        i = 1;
    }
    else if (i == 7)
    {
        instructions[5](a, b);
        i = 6;
    }
    else if (i == 10)
    {
        instructions[8](a, b);
        i = 9;
    }
    return (i);
}

int sortlist(t_list *a, t_list *b, int fd)
{
    char    *instr;
    void    (*instructions[11]) (t_ps_list *, t_ps_list *);
    int     i;

    instr = get_next_line(fd);
    instructions = {swap_a, swap_b, NULL, push_a, push_b, rotate_a, rotate_b,
        NULL, rrotate_a, rrotate_b, NULL}
    while (instr)
    {
        instr = get_next_line(fd);
        i = getfunctionindex(instr);
        if (i == -1)
            return (0);
        if (i == 2 || i == 7 || i == 10)
            i = doubleinstr(instructions, i, a, b);
        instructions[i](a, b);
    }
    return (1);
}

int instrerror(t_list **a, t_list **b, int fd)
{
    write(2, "wrong instruction\n", 18);
    ft_lstclear(a, del);
    ft_lstclear(b, del);
    close(fd);
    return (1);
}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    int     fd;

    a = NULL;
    b = NULL;
    if (argc > 1 && argc - 1 <= UINT_MAX)
    {
        if (loadlist(argc, argv, &a) == 0)
        {
            write(2, "error\n", 6);
            return (1);
        }
        fd = open("test.txt", O_RDONLY);
        if (sortlist(a, b, fd) == 0)
            return (instrerror(&a, &b, fd));
        close(fd);
        printlist(a);
        if (issorted(a))
            printf("the list is sorted\n");
        else
            printf("the list is not sorted\n");
    }
    return (0);
}
