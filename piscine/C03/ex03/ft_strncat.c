/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/24 19:58:07 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (j < nb && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(){
//     char src[] = ", world";
//     char dest[13] = "hello";

//     ft_strncat(dest, src);
//     printf("%s", dest);
//     return 0;
// }
