/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/17 20:13:16 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"initrows.h"
#include"inputcheck.h"

void	printrow(char *row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, row, 1);
		if (i < (size - 1))
			write(1, " ", 1);
		i++;
		row++;
	}
	write(1, "\n", 1);
}

int	printgrid(int numbercount, int *input)
{
	int		i;
	char	*row;

	if (isvalidinput(input, numbercount))
	{
		i = 0;
		while (i < (numbercount / 4))
		{
			row = (char *)malloc(numbercount / 4);
			initrows(input, numbercount / 4, i, row);
			printrow(row, numbercount / 4);
			free(row);
			i++;
		}
	}
	else
	{
		write(2, "Error: the input is not valid", 29);
		return (1);
	}
	return (0);
}
