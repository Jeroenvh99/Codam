/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:25:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/31 17:02:07 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stddef.h>
#include<stdarg.h>
#include<stdio.h>
#include<limits.h>

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

int	parser1(const char s, va_list args)
{
	int		printlen;
	char	*str;

	if (s == 's')
		str = va_arg(args, char *);
	else if (s == 'p')
		str = getstr_ptr(va_arg(args, uintptr_t));
	else if (s == 'd' || s == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (s == 'u')
		str = ft_uitoa(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		str = getstr_hex(va_arg(args, int), s);
	else
		return (parser2(s, args));
	printlen = ft_writestr(str, s);
	return (printlen);
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
			printlen += parser1(*s, args);
			++s;
		}
	}
	if (varargs)
		va_end(args);
	return (printlen);
}

int main(){
	void	*v;
	// ft_printf("%i\n", ft_printf("hello, this %i prints an integer\n", 24547767));
	// ft_printf("%i\n", printf("hello, this %i prints an integer\n", 24547767));
	// ft_printf("%i\n", ft_printf("hello, this %p prints a pointer\n", v));
	// ft_printf("%i\n", printf("hello, this %p prints a pointer\n", v));
	// ft_printf("%i\n", ft_printf("hello, this %x prints an integer in hex", INT_MIN));
	// ft_printf("%i\n", printf("hello, this %x prints an integer in hex", INT_MIN));
	ft_printf("%i\n", ft_printf("hello, this %p prints a pointer", LONG_MIN));
	printf("hello, this %x prints a pointer", 24547767);
	// ft_printf("%i\n", ft_printf("hello, this %i prints an integer", 24547767));
	// ft_printf("%i\n", ft_printf("hello, this %i prints an integer", 24547767));
	// ft_printf("%i\n", ft_printf("hello, this %i prints an integer", 24547767));
	return 0;
}