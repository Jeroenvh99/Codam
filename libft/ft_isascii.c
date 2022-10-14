/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:45:03 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/07 14:25:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int main(){
// 	int n;
// 	n = ft_isascii(-1);
// 	if (n){
// 		printf("-1 isn't handled correctly");
// 		return 1;
// 	}
// 	n = ft_isascii(128);
// 	if (n){
// 		printf("128 isn't handled correctly");
// 		return 1;
// 	}
// 	return 0;
// }
