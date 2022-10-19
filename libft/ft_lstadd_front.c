/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 18:09:44 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/18 09:02:45 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
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
// 	printlist(head);
// 	return 0;
// }
