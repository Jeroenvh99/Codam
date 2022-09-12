/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/09 14:31:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/11 15:28:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	rush(int a, int b);

int	main(int argc, char **argv)
{
	rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
