/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:15 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 10:19:51 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./../libft.h"

t_list	*swap_a(t_list *a)
{
	t_list	*temp;
	t_list	*newhead;

	if (!(a && a->next))
		return (NULL);
	newhead = a->next;
	a->next = a->next->next;
	a->prev = newhead;
	newhead->next = a;
	newhead->prev = NULL;
	return (newhead);
}

t_list	*swap_b(t_list *b)
{
	t_list	*temp;
	t_list	*newhead;

	if (!(b && b->next))
		return (NULL);
	newhead = b->next;
	b->next = b->next->next;
	b->prev = newhead;
	newhead->next = b;
	newhead->prev = NULL;
	return (newhead);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*current;

	if (!*b)
		return ;
	current = *b;
	if (current->next)
	{
		current->next->prev = NULL;
		*b = current->next;
	}
	else
		*b = NULL;
	if (*a)
	{
		(*a)->prev = current;
		current->next = *a;
	}
	else
		current->next = NULL;
	*a = current;
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*current;

	if (!*a)
		return ;
	current = *a;
	if (current->next)
	{
		current->next->prev = NULL;
		*a = current->next;
	}
	else
		*a = NULL;
	if (*b)
	{
		(*b)->prev = current;
		current->next = *b;
	}
	else
		current->next = NULL;
	*b = current;
}

t_list	*rotate_a(t_list *a)
{
	t_list	*temp;
	t_list	*newhead;

	if (!(a && a->next))
		return (NULL);
	temp = a;
	newhead = a->next;
	a = a->next;
	temp->next = NULL;
	a->prev = NULL;
	while (a->next)
		a = a->next;
	temp->prev = a;
	a->next = temp;
	return (newhead);
}
