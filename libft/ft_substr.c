/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:41:09 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/19 16:27:54 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*c;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		len = 0;
	else if (start + len > srclen && srclen >= start)
		len = srclen - start;
	c = malloc(len + 1);
	if (c)
	{
		i = 0;
		while (i < len)
		{
			c[i] = s[start];
			++i;
			++start;
		}
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}

// int main(){
// 	char *str = "01234";
// 	size_t size = 10;
// 	char *ret = ft_substr("hola", 4294967295, 18446744073709551615);
// 	printf("%s", ret);
// 	char *ret2 = ft_substr("", 1, 1);
// 	printf("%s", ret2);
// 	return 0;
// }
