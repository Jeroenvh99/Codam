/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initcombinations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/17 19:12:16 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	fillinrow(int rowsize, char *comb, int *initialized)
{
	int	j;

	j = 0;
	while (j < rowsize)
	{
		comb[j] = j + '1';
		j++;
	}
	*initialized = 1;
}

int	getmultiplier(int i, int rowsize)
{
	if (i == 0)
		return (2);
	else if (i == (rowsize - 1))
		return (3);
	return (0);
}

void	initrows(int *input, int rowsize, int rownumber, char *comb)
{
	int	i;
	int	k;
	int	initialized;

	i = 0;
	initialized = 0;
	while (i < rowsize)
	{
		if (!initialized)
			comb[i] = 'a';
		k = getmultiplier(i, rowsize);
		if (k)
		{
			if (input[(rowsize * k) + rownumber] == 1)
				comb[i] = rowsize + '0';
			if (input[(rowsize * k) + rownumber] == rowsize)
				fillinrow(rowsize, comb, &initialized);
		}
		if (input[i] == rowsize)
			comb[i] = rownumber + '1';
		if (input[rowsize + i] == rowsize)
			comb[i] = (rowsize - (rownumber + 1)) + '1';
		i++;
	}
}
