/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:25 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/25 17:38:39 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<unistd.h>
#include<limits.h>
#include<stdlib.h>
#include"push_swap.h"

void	singlecalls(t_list **a, t_list **b, char *instr)
{
	if (ft_strncmp(instr, "sa\n", 3) == 0)
		*a = swap(*a);
	else if (ft_strncmp(instr, "sb\n", 3) == 0)
		*b = swap(*b);
	else if (ft_strncmp(instr, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(instr, "pb\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(instr, "ra\n", 3) == 0)
		*a = rotate(*a);
	else if (ft_strncmp(instr, "rb\n", 3) == 0)
		*b = rotate(*b);
	else if (ft_strncmp(instr, "rra\n", 4) == 0)
		*a = rrotate(*a);
	else if (ft_strncmp(instr, "rrb\n", 4) == 0)
		*b = rrotate(*b);
}

void	sortlist(t_list **a, t_list **b, int fd)
{
	char	*instr;

	instr = get_next_line(fd);
	while (instr)
	{
		if (ft_strncmp(instr, "ss\n", 3) == 0)
		{
			*a = swap(*a);
			*b = swap(*b);
		}
		else if (ft_strncmp(instr, "rr\n", 3) == 0)
		{
			*a = rotate(*a);
			*b = rotate(*b);
		}
		else if (ft_strncmp(instr, "rrr\n", 4) == 0)
		{
			*a = rrotate(*a);
			*b = rrotate(*b);
		}
		else
			singlecalls(a, b, instr);
		free(instr);
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
	if (argc > 2)
	{
		if (loadlist(argc, argv, &a) == 0)
		{
			write(2, "error\n", 6);
			return (1);
		}
		fd = open("./check/test.txt", O_RDONLY);
		sortlist(&a, &b, fd);
		close(fd);
		printlist_stack(a);
		if (issorted(a))
			ft_printf("the list is sorted\n");
		else
			ft_printf("the list is not sorted\n");
		ft_lstclear(&a, del);
	}
	return (0);
}
