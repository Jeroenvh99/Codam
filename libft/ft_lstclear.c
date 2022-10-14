/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 10:12:25 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 13:52:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	del(void *node)
{
	free(node);
	node = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current->next)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

// void printlist(t_list *head){
// 	while (head){
// 		printf("%s\n", (char *)head->content);
// 		head = head->next;
// 	}
// }

// int main(){
// 	t_list *head = ft_lstnew("hello world!");
// 	ft_lstadd_front(&head, ft_lstnew("hi again!"));
// 	ft_lstadd_front(&head, ft_lstnew("hi once again!"));
// 	printlist(head);
// 	ft_lstclear(&head, &del);
// 	printlist(head);
// 	return 0;
// }
