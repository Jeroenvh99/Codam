/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/28 15:13:39 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

static int	getlength(long long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		n = ((2147483648 - n) * 2) + n;
	}
	while ((n / 16) > 0)
	{
		++count;
		n /= 16;
	}
	if (n < 16)
		++count;
	return (count);
}

static char	gethexchar(unsigned long int n, char format)
{
	if ((n % 16) < 10)
	{
		return ((n % 16) + '0');
	}
	else
	{
		if (format == 'x')
			return ((n % 16) - 10 + 'a');
		else if (format == 'X')
			return ((n % 16) - 10 + 'A');
	}
	return ('~');
}

char	*getstr_hex(long long int n, int ptr, char format)
{
	int		len;
	char	*c;

	len = getlength(n);
	if (n < 0)
	{
		n *= -1;
		n = ((2147483648 - n) * 2) + n;
	}
	if (ptr)
		len += 2;
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	c += len;
	*c = '\0';
	--c;
	while (n > 16)
	{
		*c = gethexchar(n, format);
		n /= 16;
		--c;
	}
	*c = gethexchar(n, format);
	return (c);
}

char	*ft_ptrtoa(uintptr_t ptr)
{
	char	*c;

	if (!ptr)
		return (ft_strdup("0x0"));
	c = getstr_hex(ptr, 1, 'x');
	if (!c)
		return (NULL);
	--c;
	*c = 'x';
	--c;
	*c = '0';
	return (c);
}
