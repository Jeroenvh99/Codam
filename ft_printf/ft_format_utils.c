/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:26:17 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/04 17:37:22 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	reachedtype(char s, char *format)
{
	while (*format)
	{
		if (*format == s)
			return (1);
		++format;
	}
	return (0);
}

static void	initpadinfo(t_padding *padinfo)
{
	padinfo->alternate = 'n';
	padinfo->width = -1;
	padinfo->adj = 'r';
	padinfo->sign = '-';
	padinfo->padc = ' ';
	padinfo->blank = 'n';
	padinfo->prec = -1;
}

static void	getflags(char s, t_padding *padinfo)
{
	if (s == '#')
	{
		padinfo->alternate = 'y';
	}
	else if (s == '-')
	{
		padinfo->adj = 'l';
		padinfo->padc = ' ';
	}
	else if (s == '+')
	{
		padinfo->sign = '+';
		padinfo->blank = 'n';
	}
	else if (s == ' ')
	{
		if (padinfo->sign != '+')
			padinfo->blank = 'y';
	}
	else if (s == '0')
	{
		if (padinfo->adj != 'l')
			padinfo->padc = '0';
	}
}

static int	getwidthandprecision(int i, const char *s, t_padding *padinfo)
{
	if (s[i] == '.')
	{
		padinfo->prec = 0;
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			++i;
			padinfo->prec *= 10;
			padinfo->prec += s[i] - '0';
		}
	}
	else if (s[i] >= '1' && s[i] <= '9')
	{
		padinfo->width = 0;
		padinfo->width += s[i] - '0';
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			++i;
			padinfo->width *= 10;
			padinfo->width += s[i] - '0';
		}
	}
	return (i);
}

int	getformat(const char *s, t_padding *padinfo)
{
	int	i;

	i = 0;
	initpadinfo(padinfo);
	while (!reachedtype(s[i], "cspdiuxX%") && s[i])
	{
		if (s[i] == '.' || (s[i] >= '1' && s[i] <= '9'))
		{
			i = getwidthandprecision(i, s, padinfo);
		}
		else
		{
			getflags(s[i], padinfo);
		}
		++i;
	}
	return (i);
}
