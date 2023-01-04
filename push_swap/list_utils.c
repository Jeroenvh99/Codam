#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

t_ps_list	*ps_lstnew(int *num, int index)
{
	t_ps_list	*new;

	new = malloc(sizeof(t_ps_list));
	if (!new)
		return (NULL);
	new->num = num;
    new->index = index;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_ps_list	*ps_lstlast(t_ps_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*tail;
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			tail = ps_lstlast(*lst);
			new->prev = tail;
			tail->next = new;
		}
	}
}

void	ps_lstclear(t_ps_list **lst, void (*del)(void *))
{
	t_ps_list	*current;
	t_ps_list	*temp;

	if (*lst)
	{
		current = *lst;
		while (current)
		{
			temp = current->next;
			ps_lstdelone(current, del);
			current = temp;
		}
		*lst = NULL;
	}
}

void	ps_lstdelone(t_ps_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
		(*del)(lst->num);
		free(lst);
		lst = NULL;
	}
}

void printlist(t_ps_list *head)
{
	while (head)
    {
		printf("num: %i, index: %i\n", *(head->num), head->index);
		head = head->next;
	}
}

int lstsearch(t_ps_list *lst, int *num)
{
    while (lst)
    {
        if (*(lst->num) == *num)
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
        if (lst->prev && *(lst->num) < prevnum)
            return (0);
        prevnum = *(lst->num);
        lst = lst->next;
    }
    return (1);
}
