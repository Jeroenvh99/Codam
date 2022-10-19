/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 10:39:56 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/19 16:02:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newnode = ft_lstnew(((*f)(lst->content)));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

// void *changechr(void *node){
// 	char newc[5] = "newc";
// 	((t_list *)node)->content = ((t_list *)node)->content;
// 	return (node);
// }

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
// 	t_list *newlist = ft_lstmap(head, changechr, del);
// 	printlist(newlist);
// 	return 0;
// }
