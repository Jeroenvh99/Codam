/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/13 15:44:00 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_comb2(char *combinations, int firstsize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < firstsize - 1)
	{
		while (j < firstsize)
		{
			if (j > i)
			{
				write(1, combinations + (i * 2), 2);
				write(1, " ", 1);
				write(1, combinations + (j * 2), 2);
				if (!(i == firstsize - 2 && j == firstsize - 1))
				{
					write(1, ", ", 2);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	combinations[100][2];
	int		firstindex;

	firstindex = 0;
	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			combinations[firstindex][0] = a;
			combinations[firstindex][1] = b;
			firstindex++;
			b++;
		}
		a++;
	}
	print_comb2((char *)combinations, 100);
}

// int	main(){
// 	ft_print_comb2();
// 	return (0);
// }
