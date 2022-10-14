/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:46:20 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/07 16:35:12 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<string.h>
// #include<stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		++i;
		++s;
	}
	return (i);
}

// int main()
// {
// 	int n = ft_strlen("hithere");
// 	if (n == 7){
// 		printf("the length of the string is counted correctly\n");
// 	}
// 	else{
// 		printf("the length of the string hithere isn't counted correctly");
// 		return 1;
// 	}
// 	n = ft_strlen("");
// 	if (n == 0){
// 		printf("the length of the empty string is counted correctly\n");
// 	}
// 	else{
// 		printf("the length of the empty string isn't counted correctly");
// 		return 1;
// 	}
// 	printf("inputting NULL should give a segmentation fault");
// 	n = ft_strlen(NULL);
// 	return 0;
// }