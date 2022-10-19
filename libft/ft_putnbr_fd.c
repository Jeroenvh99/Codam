/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:40:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/19 15:11:16 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

// int main(){
// 	ft_putnbr_fd(INT_MAX, 1);
// 	printf("\n");
// 	ft_putnbr_fd(INT_MIN, 1);
// 	printf("\nmin is %i, max is %i\n", INT_MIN, INT_MAX);
// 	ft_putnbr_fd(10, 1);
// 	return 0;
// }
