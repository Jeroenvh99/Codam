/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/27 19:30:03 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_atoi(char *str)
{
	long int	nb;
	int			i;
	int			multiplier;

	nb = 0;
	i = 0;
	multiplier = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			multiplier *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (multiplier < 1)
		nb *= multiplier;
	return (nb);
}

// int main(){
// 	printf("%i", ft_atoi("-2147grt483648"));
// 	return (0);
// }