/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 09:40:21 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/10 15:35:48 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*c;

	i = ft_strlen(s1);
	c = malloc(i + 1);
	if (c)
	{
		while (i >= 0)
		{
			c[i] = s1[i];
			--i;
		}
		return (c);
	}
	else
	{
		errno = ENOMEM;
		return (NULL);
	}
}

// int main(){
// 	char c[4] = "bfd";
// 	char c1[2] = "";
// 	printf("%s\n", ft_strdup(c));
// 	printf("%s\n", ft_strdup(c1));
// 	return 0;
// }