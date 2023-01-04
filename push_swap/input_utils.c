#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

int ft_isspace(char c)
{
    return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
        || c == ' ');
}

int atoi_overflow(char *str, int *num)
{
    unsigned int    res;

    res = 0;
    *num = 1;
    while (ft_isspace(*str))
		++str;
    if (*str == '+' || *str == '-')
	{
        if (*str == '-')
            *num = -1;
        ++str;
    }
    while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
        if (res - 1 >= INT_MAX)
            return (0);
		++str;
	}
    if (!*str)
    {
        *num *= res;
        return (1);
    }
    return (0);
}

int loadlisterror(t_ps_list **lst, int *num)
{
    ps_lstclear(lst, del);
    free(num);
    return (0);
}

void    reorderindex(t_ps_list *lst, int index)
{
    t_ps_list   *current;
    int         i;
    int         j;
    int         temp;

    while (index > 0)
    {
        lst = lst->next;
        --index;
    }
    while (lst->prev)
    {
        i = *(lst->num);
        j = i - 1;
        current = lst;
        while (current->prev && j > i)
            current = current->prev;
        j = *(current->num);
        if (j > i)
        {
            temp = lst->index;
            lst->index = current->index;
            current->index = temp;
        }
        lst = lst->prev;
    }
}

int loadlist(int argc, char **argv, t_ps_list **a)
{
    int i;
    int *num;

    i = 1;
    while (i < argc)
    {
        num = (int *)malloc(sizeof(int));
        if (!num)
        {
            ps_lstclear(a, del);
            return (0);
        }
        if (atoi_overflow(argv[i], num))
        {
            if (lstsearch(*a, num) == 0)
                ps_lstadd_back(a, ps_lstnew(num, i - 1));
            else
                return (loadlisterror(a, num));
            reorderindex(*a, i - 1);
        }
        else
            return (loadlisterror(a, num));
        ++i;
    }
    return (1);
}