#include<stdlib.h>
#include<stdio.h>
#include"libft.h"

void printlist(t_ps_list *head)
{
	while (head)
    {
		printf("%i\n", *(int *)head->content);
		head = head->next;
	}
}

int lstsearch(t_ps_list *lst, int *content)
{
    while (lst)
    {
        if (*(int *)lst->content == *content)
            return (1);
        lst = lst->next;
    }
    return (0);
}

void	del(void *node)
{
	free(node);
	node = NULL;
}

int     issorted(t_ps_list *lst)
{
    int prevnum;

    while (lst)
    {
        if (lst->prev && *(int *)lst->content < prevnum)
            return (0);
        prevnum = *(int *)lst->content;
        lst = lst->next;
    }
    return (1);
}
