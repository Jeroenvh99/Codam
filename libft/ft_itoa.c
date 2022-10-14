/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 14:00:49 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/14 13:53:17 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	getlength(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		++i;
		if (n < -10)
			++n;
		n *= -1;
	}
	while ((n / 10) > 0)
	{
		++i;
		n /= 10;
	}
	if (n < 10)
	{
		++i;
	}
	return (i);
}

static void	getstr(long int n, int len, char *c)
{
	if (n < 0)
	{
		*c = '-';
		n *= -1;
	}
	c += len;
	*c = '\0';
	--c;
	while (n > 9)
	{
		*c = (n % 10) + '0';
		n /= 10;
		--c;
	}
	*c = n + '0';
}

char	*ft_itoa(int n)
{
	char	*c;
	int		i;

	if (n == 0)
	{
		c = malloc(2);
		if (c)
		{
			c = "0\0";
			return (c);
		}
		return (NULL);
	}
	i = getlength(n);
	c = malloc(i + 1);
	if (c)
	{
		getstr(n, i, c);
		return (c);
	}
	return (NULL);
}

// int main(){
// 	printf("%s\n", ft_itoa(-67577));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s", ft_itoa(0));
// 	return 0;
// }
