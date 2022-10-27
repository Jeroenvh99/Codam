/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:25:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/27 11:14:21 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include<unistd.h>
#include<stddef.h>
#include<stdarg.h>
#include<stdio.h>

int	sectionlength(const char *s)
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

int	parser1(const char s, va_list args)
{
	char	*str;

	if (s == 's')
		str = va_arg(args, char *);
	else if (s == 'p')
	{
		
	}
	else if (s == 'd')
	{
		
	}
	else if (s == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (s == 'u')
	{
		
	}
	else if (s == 'x' || s == 'X')
	{
		
	}
	else
		return (parser2(s, args));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	parser2(const char s, va_list args)
{
	if (s == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (s == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	argumentscheck(const char *s)
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
			printlen += parser(*s, args);
			++s;
		}
	}
	if (varargs)
		va_end(args);
	return (printlen);
}

int main(){
	ft_printf("hello, this %s is a test", "ghukrtj");
	return 0;
}