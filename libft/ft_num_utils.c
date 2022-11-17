/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:14:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/17 09:58:34 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	getlength(long int n, t_padding *padinfo)
{
	int	count;

	count = 0;
	if (padinfo->prec > -1)
		padinfo->padc = ' ';
	if (padinfo->prec == 0 && n == 0)
		return (0);
	if (n < 0 || (n >= 0 && (padinfo->sign == '+' || padinfo->blank == 'y')))
	{
		++count;
		++padinfo->prec;
	}
	if (n < 0)
		n *= -1;
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
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
	while (i >= 0 && !c[i])
	{
		c[i] = '0';
		--i;
	}
}

char	*ft_itoa_format(long int n, t_padding *padinfo)
{
	int		len;
	char	*c;

	len = getlength(n, padinfo);
	if (padinfo->padc == '0' && padinfo->prec < 1 && padinfo->width > len)
	{
		padinfo->prec += (padinfo->width - len);
		len = padinfo->width;
	}
	if (len < padinfo->prec)
		len = padinfo->prec;
	c = ft_calloc(len + 1, 1);
	if (!c)
		return (NULL);
	getstr(n, len, c, padinfo);
	return (c);
}
