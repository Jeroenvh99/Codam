/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 13:11:20 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/27 10:39:41 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<limits.h>

static int	getnum_hex(double *temp, char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
	{
		*temp *= 16;
		if (c >= '0' && c <= '9')
			*temp += c - '0';
		else if (c >= 'a' && c <= 'f')
			*temp += c - 'a' + 10;
		else
			*temp += c - 'A' + 10;
	}
	else
		return (0);
	return (1);
}

static void	reduce_significance(int state, double *temp)
{
	if (state)
	{
		while (*temp > 1)
			*temp /= 10;
	}
}

int	ft_atof_hex_overflow(const char *str, double *res)
{
	double	temp;
	int		state;

	temp = 0;
	state = 0;
	while (*str)
	{
		if (*str == ',')
		{
			state = 1;
			*res += temp;
			temp = 0;
			++str;
		}
		if (*str == '0' && *(str + 1) == 'x')
			str += 2;
		if (getnum_hex(&temp, *str) == 0)
			break ;
		if (temp > INT_MAX)
			return (0);
		++str;
	}
	reduce_significance(state, &temp);
	*res += temp;
	return (1);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	atoi_overflow(char *str, double *num)
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
		if ((*num == 1 && res > INT_MAX) || (*num == -1 && res < INT_MAX))
			return (0);
		++str;
	}
	*num *= res;
	return (1);
}
