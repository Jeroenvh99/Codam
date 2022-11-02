/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/02 08:17:45 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

static int	getlength(unsigned long int n)
{
	int	count;

	count = 0;
	while ((n / 16) > 0)
	{
		++count;
		n /= 16;
	}
	if (n < 16)
		++count;
	return (count);
}

static char	gethexchar(int n, char format)
{
	if (n < 10)
	{
		return (n + '0');
	}
	else
	{
		if (format == 'x')
			return (n - 10 + 'a');
		else if (format == 'X')
			return (n - 10 + 'A');
	}
	return ('~');
}

char	*getstr_hex(long long int n, char format)
{
	int		len;
	char	*c;

	if (n < 0)
	{
		n *= -1;
		n = ((2147483648 - n) * 2) + n;
	}
	len = getlength(n);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	c += len;
	*c = '\0';
	--c;
	while (n >= 16)
	{
		*c = gethexchar((n % 16), format);
		n /= 16;
		--c;
	}
	*c = gethexchar((n % 16), format);
	return (c);
}

char	*getstr_ptr(uintptr_t ptr)
{
	int		len;
	char	*c;

	len = getlength(ptr) + 2;
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	c += len;
	*c = '\0';
	--c;
	while (ptr >= 16)
	{
		*c = gethexchar((ptr % 16), 'x');
		ptr /= 16;
		--c;
	}
	*c = gethexchar((ptr % 16), 'x');
	--c;
	*c = 'x';
	--c;
	*c = '0';
	return (c);
}
