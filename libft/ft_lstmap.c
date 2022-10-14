/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 10:39:56 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 12:59:38 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	newlist = NULL;
	while (lst)
	{
		newnode = malloc(sizeof(t_list));
		if (newnode)
		{
			*newnode = *((t_list *)(*f)(lst));
			if (!newlist)
			{
				newlist = newnode;
			}
			else
			{
				ft_lstadd_back(&newlist, newnode);
			}
		}
		lst = lst->next;
	}
	return (newlist);
}

static void	del(void *node)
{
	free(node);
	node = NULL;
}

void *changechr(void *node){
	char newc[5] = "newc";
	((t_list *)node)->content = ((t_list *)node)->content;
	return (node);
}

void printlist(t_list *head){
	while (head){
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

int main(){
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	printlist(head);
	t_list *newlist = ft_lstmap(head, changechr, del);
	printlist(newlist);
	return 0;
}
