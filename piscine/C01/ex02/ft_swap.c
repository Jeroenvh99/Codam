/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/15 13:57:57 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int main(){
//     int a;
//     int b;

//     a = 7;
//     b = 68;
//     ft_swap(&a, &b);
//     printf("The numbers a and b are:%d, %d", a, b);
//     return 0;
// }