/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/09 14:31:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/10 15:37:24 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//if an int has a value of 0 it will be evaluated as false
//if an int has any other value it will be evaluated as true
//a newline only needs to be printed if the character being printed is the
//last one on a row
void	ft_putchar(char *c, int lastchar, int size)
{
	write(1, c, size);
	if (lastchar)
	{
		write(1, "\n", 1);
	}
}
