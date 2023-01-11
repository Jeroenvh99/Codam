/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:25 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 10:26:37 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<limits.h>
#include"checker.h"

void	singlecalls(t_list **a, t_list **b, char *instr)
{
	if (ft_strncmp(instr, "sa", 2) == 0)
		*a = swap_a(*a);
	else if (ft_strncmp(instr, "sb", 2) == 0)
		*b = swap_b(*b);
	else if (ft_strncmp(instr, "pa", 2) == 0)
		push_a(a, b);
	else if (ft_strncmp(instr, "pb", 2) == 0)
		push_b(a, b);
	else if (ft_strncmp(instr, "ra", 2) == 0)
		*a = rotate_a(*a);
	else if (ft_strncmp(instr, "rb", 2) == 0)
		*b = rotate_b(*b);
	else if (ft_strncmp(instr, "rra", 3) == 0)
		*a = rrotate_a(*a);
	else if (ft_strncmp(instr, "rrb", 3) == 0)
		*b = rrotate_b(*b);
}

void	sortlist(t_list **a, t_list **b, int fd)
{
	char	*instr;

	instr = get_next_line(fd);
	while (instr)
	{
		if (ft_strncmp(instr, "ss", 2) == 0)
		{
			*a = swap_a(*a);
			*b = swap_b(*b);
		}
		else if (ft_strncmp(instr, "rr", 2) == 0)
		{
			*a = rotate_a(*a);
			*b = rotate_b(*b);
		}
		else if (ft_strncmp(instr, "rrr", 3) == 0)
		{
			*a = rrotate_a(*a);
			*b = rrotate_b(*b);
		}
		else
			singlecalls(a, b, instr);
		instr = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		fd;

	a = NULL;
	b = NULL;
	if (argc > 2 && argc - 1 <= UINT_MAX)
	{
		if (loadlist(argc, argv, &a) == 0)
		{
			write(2, "error\n", 6);
			return (1);
		}
		fd = open("test.txt", O_RDONLY);
		sortlist(&a, &b, fd);
		close(fd);
		printlist(a);
		if (issorted(a))
			printf("the list is sorted\n");
		else
			printf("the list is not sorted\n");
		ft_lstclear(&a, del);
	}
	return (0);
}
