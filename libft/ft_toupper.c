/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:52:31 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/05 19:54:14 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

// int main(){
// 	printf("'a' gives %c\n", (char)ft_toupper('a'));
// 	printf("'8' gives %c\n", (char)ft_toupper('8'));
// 	return 0;
// }
