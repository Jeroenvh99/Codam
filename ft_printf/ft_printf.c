/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:25:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/07 11:43:50 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stdarg.h>
#include<stdlib.h>

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
	t_padding	padinfo;

	s[0] += getformat(s[0], &padinfo);
	if (*s[0] == 's')
		str = va_arg(args, char *);
	else if (*s[0] == 'p')
		str = getstr_ptr(va_arg(args, uintptr_t), 'x', &padinfo);
	else if (*s[0] == 'd' || *s[0] == 'i')
		str = ft_itoa_format(va_arg(args, int), &padinfo);
	else if (*s[0] == 'u')
		str = ft_uitoa(va_arg(args, unsigned int), &padinfo);
	else if (*s[0] == 'x' || *s[0] == 'X')
		str = getstr_hex(va_arg(args, int), *s[0], &padinfo);
	else if (*s[0] == 'c')
		str = chartostr(va_arg(args, int));
	else if (*s[0] == '%')
		str = ft_strdup("%");
	return (ft_writestr(str, *s[0], &padinfo));
}

static int	argumentscheck(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return (1);
		++s;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		sectionlen;
	int		printlen;
	int		varargs;
	va_list	args;

	printlen = 0;
	varargs = argumentscheck(s);
	if (varargs)
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
			printlen += parser(&s, args);
			++s;
		}
	}
	if (varargs)
		va_end(args);
	return (printlen);
}
