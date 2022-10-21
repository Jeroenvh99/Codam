/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:56:03 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 13:39:48 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{	
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		--n;
	}
	return (NULL);
}

// int main(){
// 	char *mem = "9865478";
// 	printf("%s", ft_memchr(mem, '6', 6));
// 	return 0;
// }
