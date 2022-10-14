/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:54:45 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/14 17:31:57 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (ft_isascii(c))
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			if (s[i] == (char)c)
			{
				return ((char *)s + i);
			}
			--i;
		}
	}
	return (NULL);
}

// int main(){
// 	char s[15] = "adHd fdklHds";
// 	printf("%s\n", ft_strrchr(s, 'H'));
// 	printf("%s\n", ft_strrchr(s, 'g'));
// 	return 0;
// }
