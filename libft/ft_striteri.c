/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:47:05 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/12 15:06:16 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		++i;
	}
}

// void print(unsigned int index, char *c)
// {
// 	printf("%c", *c + index);
// }

// int main(){
// 	ft_striteri("Hello", print);
// }
