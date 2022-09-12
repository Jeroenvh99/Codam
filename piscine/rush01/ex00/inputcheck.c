/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inputcheck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/17 16:59:26 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	getnumberofintegers(char *argv)
{
	int	i;
	int	inputcount;

	i = 0;
	inputcount = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
		{
			inputcount++;
		}
		i++;
	}
	return (inputcount);
}

void	getinput(char *argv, int *input)
{
	int	i;

	i = 0;
	while (*argv != '\0')
	{
		if (*argv > '0' && *argv < '9')
		{
			input[i] = *argv - 48;
			i++;
		}
		argv++;
	}
}

int	isvalidinput(int *input, int size)
{
	int	i;
	int	rowsize;

	i = 0;
	rowsize = size / 4;
	while (i < size)
	{
		if (input[i] > rowsize)
		{
			return (0);
		}
		if (i < rowsize || (i > (2 * rowsize) && i < (3 * rowsize)))
		{
			if (input[i] == rowsize && input[i + rowsize] != 1)
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}
