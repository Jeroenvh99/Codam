/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 18:15:03 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/25 13:23:30 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	getlow(t_list *lst)
{
	int	current;
	int	res;
	while (lst)
	{
		current = *(int *)(lst->content);
		if (!lst->prev || current < res)
			res = current;
		lst = lst->next;
	}
	return (res);
}

int	gethigh(t_list *lst)
{
	int	current;
	int	res;

	while (lst)
	{
		current = *(int *)(lst->content);
		if (!lst->prev || current > res)
			res = current;
		lst = lst->next;
	}
	return (res);
}
