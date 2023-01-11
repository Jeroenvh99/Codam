/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_utils_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:01 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/10 15:48:13 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./../libft.h"

t_list	*rotate_b(t_list *b)
{
	t_list	*temp;
	t_list	*newhead;

	if (!(b && b->next))
		return (NULL);
	temp = b;
	newhead = b->next;
	b = b->next;
	temp->next = NULL;
	b->prev = NULL;
	while (b->next)
		b = b->next;
	temp->prev = b;
	b->next = temp;
	return (newhead);
}

t_list	*rrotate_a(t_list *a)
{
	t_list	*current;
	t_list	*newhead;

	if (!(a && a->next))
		return (NULL);
	current = a;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	a->prev = current;
	current->next = a;
	newhead = current;
	return (newhead);
}

t_list	*rrotate_b(t_list *b)
{
	t_list	*current;
	t_list	*newhead;

	if (!(b && b->next))
		return (NULL);
	current = b;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	b->prev = current;
	current->next = b;
	newhead = current;
	return (newhead);
}
