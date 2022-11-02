/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:09:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/02 11:48:48 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stdlib.h>

static int	getlength(unsigned int n)
{
	int	count;

	count = 0;
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*c;

	len = getlength(n);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
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
	return (c);
}

char	*chartostr(int c)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}

int	ft_writestr(char *s, char format, t_padding *padinfo)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (format == 'c')
		len = 1;
	else
		len = ft_strlen(s);
	if (len > padinfo->precision)
		len = padinfo->precision;
	write(1, s, len);
	if (format != 's')
		free(s);
	return (len);
}
