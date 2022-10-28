/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:09:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/28 13:25:11 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include<unistd.h>
#include<stdlib.h>

static int	getlength(unsigned int n)
{
	int	count;

	count = 0;
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*c;

	len = getlength(n);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
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
	return (c);
}

void	ft_writestr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	else
		write(1, "(null)", 6);
}
