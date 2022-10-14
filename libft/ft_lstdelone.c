/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:41:37 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 10:23:02 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	del(void *node)
{
	free(node);
	node = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst);
}

// int main(){
// 	t_list *head = ft_lstnew("hello world!");
// 	ft_lstdelone(head, &del);
// 	return 0;
// }
