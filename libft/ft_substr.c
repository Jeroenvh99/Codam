/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:41:09 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/13 18:51:20 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	getlength(const char *s, int start, size_t len)
{
	int	len0;

	len0 = ft_strlen(s);
	if (len0 - len < start + 1)
	{
		len = (size_t)(len0 - start + 1);
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*c;

	if (!s || !*s)
	{
		return (NULL);
	}
	len = getlength(s, start, len);
	c = malloc(len + 1);
	if (c)
	{
		s += start;
		i = 0;
		while (*s && i < len)
		{
			c[i] = s[i];
			++i;
		}
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}

int main(){
	printf("%s", ft_substr("hithereworld!", 3, 4));
	return 0;
}
