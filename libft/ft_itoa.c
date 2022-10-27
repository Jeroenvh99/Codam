/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 14:00:49 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/27 10:48:42 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static int	getlength(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		++count;
		n *= -1;
	}
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	return (count);
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
	int		outlen;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	outlen = getlength(n);
	c = malloc(outlen + 1);
	if (!c)
		return (NULL);
	getstr(n, outlen, c);
	return (c);
}
