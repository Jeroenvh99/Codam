/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:26:17 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/02 08:58:40 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	reachedtype(char s)
{
	int	i;

	i = 0;
	char	formats[10] = "cspdiuxX%";
	while (formats[i])
	{
		if (formats[i] == s)
			return (1);
		++i;
	}
	return (0);
}

void	initpadinfo(t_padding *padinfo)
{
	padinfo->alternate = 'n';
	padinfo->width = 0;
	padinfo->adjustment = 'r';
	padinfo->sign = '-';
	padinfo->padchar = ' ';
	padinfo->blank = 'n';
	padinfo->precision = 0;
}

int	getformat(char *s, t_padding *padinfo)
{
	int	i;

	i = 0;
	while (!reachedtype(s[i]) && s[i])
	{
		if (s[i] == '#')
		{
			padinfo->alternate = 'y';
		}
		else if (s[i] == '-')
		{
			padinfo->adjustment = 'l';
			if (padinfo->padchar == '0')
			{
				padinfo->padchar = ' ';
			}
		}
		else if (s[i] == '+')
		{
			padinfo->sign = '+';
			if (padinfo->blank == 'y')
			{
				padinfo->blank = 'n';
			}
		}
		else if (s[i] == ' ')
		{
			if (padinfo->sign != '+')
				padinfo->blank = 'y';
		}
		else if (s[i] == '0')
		{
			if (padinfo->adjustment != 'l')
				padinfo->padchar = '0';
		}
		else if (s[i] == '.')
		{
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				++i;
				padinfo->precision *= 10;
				padinfo->precision += s[i] - '0';
			}
		}
		else if (s[i] >= '1' && s[i] <= '9')
		{
			padinfo->width += s[i] - '0';
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				++i;
				padinfo->width *= 10;
				padinfo->width += s[i] - '0';
			}
		}
		++i;
	}
	return (i);
}