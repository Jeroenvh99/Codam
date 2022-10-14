/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:53:59 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/14 17:31:38 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (ft_isascii(c))
	{
		i = 0;
		while (i == 0 || s[i - 1])
		{
			if (s[i] == (char)c)
			{
				return ((char *)s + i);
			}
			++i;
		}
	}
	return (NULL);
}

int main(){
	char s[15] = "teste";
	printf("%s\n", ft_strchr(s, 'e'));
	// printf("%s\n", ft_strchr(s, 'g'));
	return 0;
}
