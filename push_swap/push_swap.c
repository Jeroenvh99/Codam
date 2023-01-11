/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:14:09 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 11:23:05 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*a;
	t_ps_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 2 && argc - 1 <= UINT_MAX)
	{
		if (loadlist(argc, argv, &a) == 0)
		{
			write(2, "error\n", 6);
			return (1);
		}
		if (issorted(a))
			return (0);
		printlist(a);
	}
	return (0);
}
