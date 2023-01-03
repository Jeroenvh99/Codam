#include<unistd.h>
#include<limits.h>
#include<stdlib.h>
#include"push_swap.h"

gcc push_swap.c ../libft/ft_lstadd_back.c ../libft/ft_lstnew.c ../libft/ft_lstclear.c ../libft/ft_lstdelone.c ../libft/ft_lstlast.c input_utils.c list_utils.c ../libft/ft_printf.c ../libft/ft_printf_utils.c ../libft/ft_num_utils.c ../libft/ft_format_utils.c ../libft/ft_hex_utils.c ../libft/ft_calloc.c ../libft/ft_strdup.c ../libft/ft_strchr.c ../libft/ft_memset.c ../libft/ft_strlen.c ../libft/ft_strnstr.c ../libft/ft_strncmp.c 

void    switchindex(t_list **lst, int first, int second)
{
    int     temp;
    t_list  *current;
    t_list  *current2;

    current = *lst;
    while (second > 0)
    {
        current = current->next;
        --first;
        --second;
    }
    current2 = current;
    while (first > 0)
    {
        current = current->next;
        --first;
    }
    temp = *(int *)current2->content;
    *(int *)current2->content = *(int *)current->content;
    *(int *)current->content = temp;
}

void    reorderlist(t_list *oldlst, t_list **newlst, int i)
{
    int a;
    int b;
    int j;

    j = i;
    a = *(int *)oldlst->content;
    b = a - 1;
    while (a > b)
    {
        oldlst = oldlst->prev;
        b = *(int *)oldlst->content;
        --j;
    }
    switchindex(newlst, i, j);
}

t_list    *unsignlist(t_list *lst)
{
    unsigned int    i;
    unsigned int    *num;
    t_list          *newlist;

    newlist = NULL;
    i = 0;
    while(lst)
    {
        num = malloc(sizeof(unsigned int));
        if (!num)
        {
            ft_lstclear(&newlist, del);
            return (NULL);
        }
        *num = i;
        ft_lstadd_back(&newlist, ft_lstnew(num));
        if (lst->prev)
            reorderlist(lst, &newlist, i);
        lst = lst->next;
        ++i;
    }
    return (newlist);
}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

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
        a = unsignlist(a);
        printlist(a);
    }
    return (0);
}