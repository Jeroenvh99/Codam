/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:54:45 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/19 15:55:04 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		--i;
	}
	return (NULL);
}

// int main(){
// 	char s[15] = "adHd fdklHds";
// 	printf("%s\n", ft_strrchr(s, 543));
// 	printf("%s\n", ft_strrchr(s, 'g'));
// 	return 0;
// }
