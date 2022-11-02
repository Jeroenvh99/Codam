/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:14:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/02 10:20:15 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<stdlib.h>

static int	getlength(int n, char sign, char blank)
{
	int	count;

	count = 0;
	if (n > 0 && (sign == '+' || blank == 'y'))
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

static char	*getstr(long int n, int len, char *c, t_padding *padinfo)
{
	if (padinfo->sign == '+' && n >= 0)
		*c = '+';
	if (padinfo->blank == 'y' && n >= 0)
		*c = ' ';
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
	if (*(c - 1) == '-' || padinfo->sign == '+' || padinfo->blank == 'y')
		return (c - 1);
	return (c);
}

char	*ft_itoa_format(int n, t_padding *padinfo)
{
	int		len;
	char	*c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = getlength(n, padinfo->sign, padinfo->blank);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	getstr(n, len, c, padinfo);
	return (c);
}
