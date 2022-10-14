/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:16:19 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 09:27:36 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
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
// 	printf("%s\n", ft_lstlast(head)->content);
// 	printlist(head);
// 	return 0;
// }
