/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 09:24:41 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/07 14:25:46 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(){
// 	printf("the following character is on the standard error:");
// 	ft_putchar_fd('g', 1);
// 	printf("\nthe following character is on the standard output:");
// 	ft_putchar_fd('k', 1);
// 	ft_putchar_fd('d', 1);
// 	return 0;
// }
