/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:54 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 10:36:17 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

void	printlist(t_list *head)
{
	while (head)
	{
		ft_printf("num: %i, current: %p, prev: %p, next: %p\n", *((int *)head->content), head, head->prev, head->next);
		head = head->next;
	}
}

int	lstsearch(t_list *lst, int *num)
{
	while (lst)
	{
		if (*((unsigned int *)lst->content) == *num)
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
		if (*((int *)lst->content) < prevnum)
			return (0);
		prevnum = *((int *)lst->content);
		lst = lst->next;
	}
	return (1);
}
