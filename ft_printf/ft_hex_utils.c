/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/27 16:53:00 by jvan-hal      ########   odam.nl         */
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

static char	gethexchar(long long int n, char format)
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

static char	*getstr(long long int n, int len, int ptr, char format)
{
	char	*c;

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
	if (ptr)
	{
		--c;
		*c = 'x';
		--c;
		*c = '0';
	}
	return (c);
}

char	*ft_itoa_hex(int n, const char format )
{
	if (n == -2147483648)
		return (ft_strdup("80000000"));
	return (getstr(n, getlength(n), 0, format));
}

char	*ft_ptrtoa(uintptr_t ptr)
{
	char *c;

	if (!ptr)
		return (ft_strdup("0x0"));
	return (getstr(ptr, getlength(ptr), 1, 'x'));
}

int main(){
	void	*v;
	
	printf("%s\n", ft_ptrtoa((uintptr_t)v));
	printf("%p\n", v);
	printf("%s\n", ft_itoa_hex(INT_MIN + 1, 'x'));
	printf("%x", INT_MIN + 1);
	return 0;
}