/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultimate_div_mod.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/15 11:46:25 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tempa;

	tempa = *a;
	*a /= *b;
	*b = tempa % *b;
}

// int main(){
// 	int a;
// 	int b;

// 	a = 7;
// 	b = 4;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("The value of a is %i and b is %i", a, b);
// 	return 0;
// }