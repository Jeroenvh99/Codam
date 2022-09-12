/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/17 20:11:20 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"inputcheck.h"
#include"output.h"

int	main(int argc, char **argv)
{
	int	*input;
	int	numbercount;
	int	statuscode;

	statuscode = 0;
	numbercount = getnumberofintegers(argv[1]);
	input = (int *)malloc(numbercount * 4);
	getinput(argv[1], input);
	statuscode = printgrid(numbercount, input);
	free(input);
	return (statuscode);
}
