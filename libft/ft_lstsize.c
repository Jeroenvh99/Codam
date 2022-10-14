/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 18:04:42 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/10 18:28:55 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}

// int main(){
// 	t_list *head = ft_lstnew("hello world!");
// 	ft_lstadd_front(&head, ft_lstnew("hi again!"));
// 	printf("%i", ft_lstsize(head));
// 	return 0;
// }
