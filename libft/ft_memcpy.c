/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:49:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/18 15:21:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src && n != 0)
	{
		return (dst);
	}
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		++i;
	}
	return (dst);
}

// int main(){
// 	ft_memcpy(NULL, NULL, 5);
// 	return (0);
// }