/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 09:38:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/13 10:41:26 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

int	ft_atoi(const char *str)
{
	int	out;
	int	i;

	while (*str == '\t' || *str == '\n' || *str == 'v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	if ((*str == '+' || *str == '-') && *(str + 1) >= '0' && *(str + 1) <= '9')
		++str;
	else if (!(*str >= '0' && *str <= '9'))
		return (0);
	out = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		out *= 10;
		out += str[i] - '0';
		++i;
	}
	if (*(str - 1) == '-')
		out *= -1;
	return (out);
}

// int main(){
// 	printf("%i",ft_atoi("     -658jgh3"));
// 	return 0;
// }