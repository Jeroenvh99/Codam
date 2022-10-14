/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 09:53:44 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/11 09:40:22 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	n;

	while (*s)
	{
		write(fd, s, 1);
		++s;
	}
	n = '\n';
	write(fd, &n, 1);
}

// int main(){
// 	ft_putendl_fd("string is on standard output followed by a newline", 1);
// 	return 0;
// }
