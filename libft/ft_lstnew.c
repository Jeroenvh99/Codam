/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:48:22 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/18 18:26:12 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = content;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

// int main(){
// 	t_list *node = ft_lstnew("hello world!");
// 	printf("%s", (char *)node->content);
// 	return 0;
// }
