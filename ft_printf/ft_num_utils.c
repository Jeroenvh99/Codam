/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:14:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/03 15:16:23 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<stdlib.h>

static int	getlength(int n, char sign, char blank, int precision)
{
	int	count;

	count = 0;
	if (n > 0 && (sign == '+' || blank == 'y'))
	{
		++count;
		++precision;
	}
	if (n < 0)
	{
		++count;
		++precision;
		n *= -1;
	}
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

static void	getstr(long int n, int i, char *c, t_padding *padinfo)
{
	if (padinfo->sign == '+' && n >= 0)
		c[0] = '+';
	if (padinfo->blank == 'y' && n >= 0)
		c[0] = ' ';
	if (n < 0)
	{
		c[0] = '-';
		n *= -1;
	}
	--i;
	while (n > 9)
	{
		c[i] = (n % 10) + '0';
		n /= 10;
		--i;
	}
	c[i] = n + '0';
	--i;
	while (i >= 0 && c[i] != '+' && c[i] != '-' && c[i] != ' ')
	{
		c[i] = '0';
		--i;
	}
}

char	*ft_itoa_format(int n, t_padding *padinfo)
{
	int		len;
	char	*c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = getlength(n, padinfo->sign, padinfo->blank, padinfo->precision);
	c = ft_calloc(len + 1, 1);
	if (!c)
		return (NULL);
	getstr(n, len, c, padinfo);
	return (c);
}
