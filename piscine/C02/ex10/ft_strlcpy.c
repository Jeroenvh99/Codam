/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/24 19:32:40 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

int main(){
	char	src[6] = "er her";
	char	dest[10] = "jeg ";
	ft_strlcpy(dest, src, 6);
	printf("%s", dest);
	return 0;
}