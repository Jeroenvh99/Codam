/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush04.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/09 14:31:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/10 15:34:36 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char *c, int lastChar, int size);

void	print_first_row(char *c, int x, int maxrows)
{
	int	lastchar;

	lastchar = 0;
	if (x == 0)
	{
		*c = 'A';
	}
	else if (x > 0 && x < maxrows - 1)
	{
		*c = 'B';
	}
	else
	{
		*c = 'C';
		lastchar = 1;
	}
	ft_putchar(c, lastchar, 1);
}

void	print_middle_rows(char *c, int x, int maxrows)
{
	int	lastchar;

	lastchar = 0;
	if (x == 0)
	{
		*c = 'B';
	}
	else if (x > 0 && x < maxrows - 1)
	{
		*c = ' ';
	}
	else
	{
		*c = 'B';
		lastchar = 1;
	}
	ft_putchar(c, lastchar, 1);
}

void	print_last_row(char *c, int x, int maxrows)
{
	int	lastchar;

	lastchar = 0;
	if (x == 0)
	{
		*c = 'C';
	}
	else if (x > 0 && x < maxrows - 1)
	{
		*c = 'B';
	}
	else
	{
		*c = 'A';
		lastchar = 1;
	}
	ft_putchar(c, lastchar, 1);
}

void	print_rows(int x, int y, int a, int b)
{
	char	c;

	while (y < b)
	{
		while (x < a)
		{
			if (y == 0)
			{
				print_first_row(&c, x, a);
			}
			else if (y > 0 && y < b - 1)
			{
				print_middle_rows(&c, x, a);
			}
			else
			{
				print_last_row(&c, x, a);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	rush(int a, int b)
{
	int	x;
	int	y;

	if (a > 0 && b > 0)
	{
		x = 0;
		y = 0;
		print_rows(x, y, a, b);
	}
	else
	{
		ft_putchar("Error: x or y was negative or zero", 0, 34);
	}
}
