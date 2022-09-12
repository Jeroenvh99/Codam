/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_negative.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/13 15:51:42 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_is_negative(int number)
{
	char	sign;

	if (number < 0)
	{
		sign = 'N';
	}
	else
	{
		sign = 'P';
	}
	write(1, &sign, 1);
}

// int	main(){
// 	ft_is_negative((int)NULL);
// 	ft_is_negative(5);
// 	ft_is_negative(-8);
// 	return (0);
// }