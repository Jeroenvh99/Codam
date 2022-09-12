/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupcase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/22 14:25:59 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

// int main(){
// 	char c[] = "asdfDFHgfgh";
// 	ft_strupcase(c);
// 	printf("%s", c);
// 	return 0;
// }