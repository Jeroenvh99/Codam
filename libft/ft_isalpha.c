/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:30:24 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/07 14:25:36 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.hv

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// int main(){
// 	char c = '\0';
// 	int n = 0;
// 	while (c < 127){
// 		int i = ft_isalpha(c);
// 		printf("the character %c is %i alpha\n", c, i);
// 		++c;
// 		if (i){
// 			++n;
// 		}
// 	}
// 	if (n == 52){
// 		printf("the correct number of alpha characters is found");
// 	}
// 	return 0;
// }
