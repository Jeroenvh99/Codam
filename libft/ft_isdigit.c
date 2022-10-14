/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:43:39 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/05 09:30:46 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int main(){
// 	int n = ft_isdigit('g');
// 	if (n){
// 		printf("g is recognized as a digit");
// 		return 1;
// 	}
// 	n = ft_isdigit('5');
// 	if (!n){
// 		printf("5 is not recognized as a digit");
// 	}
// 	return 0;
// }