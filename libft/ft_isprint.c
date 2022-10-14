/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:45:41 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/05 18:37:32 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int main(){
// 	char c = '\0';
// 	int n = 0;
// 	while (c <= 127){
// 		int i = ft_isprint(c);
// 		printf("the character %c is %i printable\n", c, i);
// 		++c;
// 		if (i){
// 			++n;
// 		}
// 		if (c == 1 && n > 1){
// 			break;
// 		}
// 	}
// 	if (n == 95){
// 		printf("the correct number of printable characters is found");
// 	}
// 	return 0;
// }
