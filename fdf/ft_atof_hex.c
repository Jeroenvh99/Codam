/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 13:11:20 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/16 16:52:42 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

double	ft_atof_hex(const char *str)
{
	double	res;
	double	temp;
	int		state;

	res = 0;
	temp = 0;
	state = 0;
	while (*str)
	{
		if (*str == ',')
		{
			state = 1;
			res += temp;
			temp = 0;
			++str;
		}
		if (*str == '0' && *(str + 1) == 'x')
			str += 2;
		if (getnum_hex(&temp, *str) == 0)
			break ;
		++str;
	}
	reduce_significance(state, &temp);
	res += temp;
	return (res);
}
