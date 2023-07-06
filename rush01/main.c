/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 09:24:49 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/07/03 14:56:05 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_arrlen(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		++i;
	return (i);
}

char	*init_board(int size)
{
	char	*board;
	size_t	i;

	board = malloc(sizeof(char) * size);
    if (!board)
        return NULL;
	i = 0;
	while (i < size)
	{
		board[i] = '0';
		++i;
	}
	return (board);
}

int valid()
{
    int i;
    int up;
    int down;
    int left;
    int right;

    i = index - 1;
    while
}

int	solve(char *board, int size, int index, char solution)
{
	char	c;

	c = '1';
	if (index == size)
		return 1;
    board[index] = solution;
    update_visibility(board, visible);
	if (!valid(board, size, index))
	{
		board[index] = '0';
		return 0;
	}
	if (valid(board, size, index))
	{
		while (c <= size - '0')
		{
			if (solve(board, size, index + 1, c))
                return 1;
			++c;
		}
	}
    return 0;
}

int	main(int argc, char **argv)
{
	int size;
	char *board;

	size = ft_arrlen(argv);
	if (size % 4 != 0)
	{
		return (1);
	}
	board = init_board(size);
	solve(board, size, 0, '0');
	free(board);
	return (0);
}
