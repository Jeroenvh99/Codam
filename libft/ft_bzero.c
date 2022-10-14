/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:49:09 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 13:49:31 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main(){
// 	char c[9] = "testtest";
// 	printf("%s\n", c);
// 	ft_bzero(c, 0);
// 	printf("when n is 0 the string is %s\n", c);
// 	ft_bzero(c, 3);
// 	char *d = c + 3;
// 	printf("when n is 3 the string is %s\n", d);
// 	return 0;
// }