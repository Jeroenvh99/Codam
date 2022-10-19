/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:41:37 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/19 16:04:04 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
	{
		return ;
	}
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
		lst = NULL;
	}
}

// void	del(void *node)
// {
// 	free(node);
// 	node = NULL;
// }

// int main(){
// 	t_list *head = ft_lstnew("hello world!");
// 	ft_lstdelone(head, &del);
// 	return 0;
// }
