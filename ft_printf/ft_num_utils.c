/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:14:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/02 08:15:09 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include<stdlib.h>

static int	getlength(int n, char sign)
{
	int	count;

	count = 0;
	if (sign == '+' && n > 0)
		++count;
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

static char	*getstr(long int n, int len, char sign)
{
	char	*c;

	c = malloc(len + 1);
	if (!c)
		return (NULL);
	if (sign == '+' && n >= 0)
		*c = '+';
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
	if (*(c - 1) == '-' || sign == '+')
		return (c - 1);
	return (c);
}

char	*ft_itoa_format(int n, char sign)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (getstr(n, getlength(n, sign), sign));
}
