/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:54 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/25 19:30:32 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

void	printlist_stack(t_list *head)
{
	while (head)
	{
		ft_printf("num: %i\n", *((int *)head->content));
		head = head->next;
	}
}

void	printlist_instr(t_list *head)
{
	while (head)
	{
		ft_printf("%s\n", (char *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}

int	lstsearch(t_list *lst, int *num)
{
	while (lst)
	{
		if (*((int *)lst->content) == *num)
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

int	issorted(t_list *lst)
{
	int	prevnum;

	while (lst)
	{
		if (lst->prev && *((int *)lst->content) < prevnum)
			return (0);
		prevnum = *((int *)lst->content);
		lst = lst->next;
	}
	return (1);
}
