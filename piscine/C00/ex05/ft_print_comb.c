/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/09 12:05:48 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_comb(char *a, char *b, char *c)
{
	write(1, a, 1);
	write(1, b, 1);
	write(1, c, 1);
	if (*a < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '9')
	{
		b = a + 1;
		while (b <= '9')
		{
			c = b + 1;
			while (c <= '9')
			{
				print_comb(&a, &b, &c);
				c++;
			}
			b++;
		}
		a++;
	}
}

//int	main(){
//	ft_print_comb();
//	return (0);
//}