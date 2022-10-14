/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:43:27 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/13 12:40:39 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	getstartindex(const char *s, const char *set)
{
	int	i;
	int	j;
	int	inset;

	i = 0;
	while (s[i])
	{
		j = 0;
		inset = 0;
		while (!inset && set[j])
		{
			if (s[i] == set[j])
			{
				inset = 1;
			}
			++j;
		}
		if (!inset)
		{
			break ;
		}
		++i;
	}
	return (i);
}

static int	getlastindex(const char *s, const char *set)
{
	int	i;
	int	j;
	int	inset;

	i = ft_strlen(s) - 1;
	while (s[i])
	{
		j = 0;
		inset = 0;
		while (!inset && set[j])
		{
			if (s[i] == set[j])
			{
				inset = 1;
			}
			++j;
		}
		if (!inset)
		{
			break ;
		}
		--i;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		end;
	char	*c;

	i = getstartindex(s1, set);
	end = getlastindex(s1, set);
	c = malloc(end - i + 2);
	if (c)
	{
		j = 0;
		while (i <= end)
		{
			c[j] = s1[i];
			++j;
			++i;
		}
		c[j] = '\0';
		return (c);
	}
	return (NULL);
}

// int main(){
// 	printf("%s", ft_strtrim("aabbcbcddee", "abe"));
// 	return 0;
// }
