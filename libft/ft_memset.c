/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:48:44 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/13 12:48:51 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)(c);
		++i;
	}
	return (b);
}

// int main(){
// 	char c[6] = "hello";
// 	printf("%s\n", c);
// 	ft_memset(c, 5, 3);
// 	printf("%s", c);
// 	return 0;
// }
