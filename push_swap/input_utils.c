/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:13:34 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/23 18:16:38 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<limits.h>
#include<stdlib.h>
#include"push_swap.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	atoi_overflow(char *str, int *num)
{
	unsigned int	res;

	res = 0;
	*num = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*num = -1;
		++str;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > 0 && res - 1 >= INT_MAX)
			return (0);
		++str;
	}
	if (!*str)
	{
		*num *= res;
		return (1);
	}
	return (0);
}

int	loadlisterror(t_list **lst, void *num)
{
	ft_lstclear(lst, del);
	free(num);
	return (0);
}

int	loadlist(int argc, char **argv, t_list **a)
{
	int	i;
	int	*num;

	i = 1;
	while (i < argc)
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
		{
			ft_lstclear(a, del);
			return (0);
		}
		if (atoi_overflow(argv[i], num))
		{
			if (lstsearch(*a, num) == 0)
				ft_lstadd_back(a, ft_lstnew(num));
			else
				return (loadlisterror(a, num));
		}
		else
			return (loadlisterror(a, num));
		++i;
	}
	return (1);
}
