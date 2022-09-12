/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_printable.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/22 14:19:38 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0' )
	{
		if (*str < 32 || *str == 127)
			return (0);
		str++;
	}
	return (1);
}

// int main(){
// 	printf("%i", ft_str_is_printable("dgdfhygj"));
// 	return 0;
// }