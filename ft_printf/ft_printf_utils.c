/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:09:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/03 15:17:38 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stdlib.h>

static int	getlength(unsigned int n, int precision)
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
	if (precision > -1 && count < precision)
		count = precision;
	return (count);
}

char	*ft_uitoa(unsigned int n, int precision)
{
	int		i;
	char	*c;

	i = getlength(n, precision);
	c = ft_calloc(i + 1, 1);
	if (!c)
		return (NULL);
	--i;
	while (n > 9)
	{
		c[i] = (n % 10) + '0';
		n /= 10;
		--i;
	}
	c[i] = n + '0';
	while (i > 0)
	{
		--i;
		c[i] = '0';
	}
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
	if (format == 's' && padinfo->precision > -1 && len > padinfo->precision)
		len = padinfo->precision;
	write(1, s, len);
	if (format != 's')
		free(s);
	return (len);
}
