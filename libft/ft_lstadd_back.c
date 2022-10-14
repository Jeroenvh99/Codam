/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:28:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 13:44:04 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	ft_lstlast(*lst)->next = new;
}

// void printlist(t_list *head){
// 	while (head){
// 		printf("%s\n", (char *)head->content);
// 		head = head->next;
// 	}
// }

// int main(){
// 	t_list *head = ft_lstnew("hello world!");
// 	ft_lstadd_back(&head, ft_lstnew("hi again!"));
// 	printlist(head);
// 	return 0;
// }
