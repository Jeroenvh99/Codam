/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/03 11:10:14 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<stdlib.h>

static int	getlength(unsigned long int n, int precision)
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
	if (precision > -1 && count < precision)
		count = precision;
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

char	*getstr_ptr(uintptr_t ptr, char format, int precision)
{
	int		i;
	char	*c;

	i = getlength(ptr, precision) + 2;
	c = ft_calloc(i + 1, 1);
	if (!c)
		return (NULL);
	--i;
	while (ptr >= 16)
	{
		c[i] = gethexchar((ptr % 16), format);
		ptr /= 16;
		--i;
	}
	c[i] = gethexchar((ptr % 16), format);
	--i;
	while (i > 1)
	{
		c[i] = '0';
		--i;
	}
	c[i] = format;
	--i;
	c[i] = '0';
	return (c);
}

char	*getstr_hex(long long int n, char format, char alternate,
		int precision)
{
	int		i;
	char	*c;

	if (n < 0)
		n = ((2147483648 + n) * 2) - n;
	if (alternate == 'y' && n > 0)
		return (getstr_ptr(n, format, precision));
	i = getlength(n, precision);
	c = ft_calloc(i + 1, 1);
	if (!c)
		return (NULL);
	--i;
	while (n >= 16)
	{
		c[i] = gethexchar((n % 16), format);
		n /= 16;
		--i;
	}
	c[i] = gethexchar((n % 16), format);
	while (i > 0)
	{
		--i;
		c[i] = '0';
	}
	return (c);
}
