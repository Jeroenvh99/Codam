/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:09:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/07 09:15:41 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stdlib.h>

static int	getlength(unsigned int n, t_padding *padinfo)
{
	int	count;

	count = 0;
	if (padinfo->prec == 0 && n == 0)
		return (0);
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	if (count < padinfo->prec)
		count = padinfo->prec;
	if (padinfo->prec > -1)
		padinfo->padc = ' ';
	if (padinfo->padc == '0' && padinfo->prec < 1 && padinfo->width > count)
	{
		padinfo->prec += (padinfo->width - count);
		count = padinfo->width;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n, t_padding *padinfo)
{
	int		i;
	char	*c;

	i = getlength(n, padinfo);
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
	int	preformlen;
	int	postformlen;

	if (!s)
		s = ft_strdup("(null)");
	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (format == 'c')
		len = 1;
	if (format == 's' && padinfo->prec > -1 && len > padinfo->prec)
		len = padinfo->prec;
	preformlen = printpreformatting(len, padinfo);
	if (preformlen == -1)
		return (-1);
	write(1, s, len);
	if (format != 's' || ft_strnstr(s, "(null)", 6))
		free(s);
	postformlen = printpostformatting(len, padinfo);
	if (postformlen == -1)
		return (-1);
	return (len + preformlen + postformlen);
}
