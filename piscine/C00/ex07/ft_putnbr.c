/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/20 16:58:11 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		digits;
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb)
	{
		c = nb % 10 + '0';
		write(1, &c, 1);
		nb /= 10;
	}
}

int main(){
   ft_putnbr(-5);
   return (0);
}