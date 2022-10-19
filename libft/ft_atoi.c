/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 09:38:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/17 10:59:48 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include<stdlib.h>

int	ft_atoi(const char *str)
{
	int	out;
	int	i;

	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
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
// 	char *n = "\t\v\f\r\n \f-06050";
// 	int i1 = atoi(n);
// 	int i2 = ft_atoi(n);
// 	printf("%i\n", i1);
// 	printf("%i\n", i2);
// 	return 0;
// }
