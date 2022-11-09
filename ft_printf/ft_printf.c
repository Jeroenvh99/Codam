/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:25:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/09 11:19:51 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

static int	sectionlength(const char *s)
{
	int	count;

	count = 0;
	while (*s && *s != '%')
	{
		++count;
		++s;
	}
	return (count);
}

static char	*chartostr(int c)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}

static int	parser(const char **s, va_list args)
{
	char		*str;
	char		type;
	t_padding	padinfo;

	s[0] += getformat(s[0], &padinfo);
	type = *s[0];
	if (type == 's')
		str = va_arg(args, char *);
	else if (type == 'p')
		str = getstr_ptr(va_arg(args, uintptr_t), 'x', &padinfo);
	else if (type == 'd' || type == 'i')
		str = ft_itoa_format(va_arg(args, int), &padinfo);
	else if (type == 'u')
		str = ft_uitoa(va_arg(args, unsigned int), &padinfo);
	else if (type == 'x' || type == 'X')
		str = getstr_hex(va_arg(args, int), *s[0], &padinfo);
	else if (type == 'c')
		str = chartostr(va_arg(args, int));
	else if (type == '%')
		str = chartostr('%');
	else
		str = chartostr(type);
	++s[0];
	return (ft_writestr(str, type, &padinfo));
}

int	ft_printf(const char *s, ...)
{
	int		sectionlen;
	int		printlen;
	va_list	args;

	printlen = 0;
	va_start(args, s);
	while (*s)
	{
		sectionlen = sectionlength(s);
		write(1, s, sectionlen);
		s += sectionlen;
		printlen += sectionlen;
		if (*s)
		{
			++s;
			if (!*s)
				break ;
			sectionlen = parser(&s, args);
			if (sectionlen == -1)
				return (-1);
			printlen += sectionlen;
		}
	}
	va_end(args);
	return (printlen);
}
