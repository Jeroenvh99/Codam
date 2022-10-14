/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 09:50:11 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/07 14:26:21 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		++s;
	}
}

// int main(){
// 	ft_putstr_fd("this is a string that's printed to standard output", 1);
// 	return 0;
// }
