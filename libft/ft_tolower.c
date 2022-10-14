/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:53:19 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/05 19:52:50 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

// int main(){
// 	printf("'A' gives %c\n", (char)ft_tolower('a'));
// 	printf("'8' gives %c\n", (char)ft_tolower('8'));
// 	return 0;
// }
