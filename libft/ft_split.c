/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:44:31 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 15:49:49 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static int	getarrlength(const char *c, char dlm)
{
	int		count;
	int		j;
	char	prevc;

	count = 0;
	j = 0;
	prevc = dlm;
	while (j == 0 || c[j - 1])
	{
		if ((c[j] == dlm && prevc != dlm) || (!c[j] && prevc != dlm))
			++count;
		prevc = c[j];
		++j;
	}
	return (count);
}

static int	getend(const char *s, char dlm)
{
	int		i;
	char	prevc;

	i = 0;
	while (i == 0 || s[i - 1])
	{
		if ((s[i] == dlm && prevc != dlm) || (s[i] == '\0' && prevc != dlm))
		{
			return (i);
		}
		prevc = s[i];
		++i;
	}
	return (0);
}

static int	fillarr(char **arr, const char *s, char dlm)
{
	int	i;
	int	sublength;

	i = 0;
	while (*s)
	{
		if (*s == dlm)
		{
			++s;
		}
		else
		{
			sublength = getend(s, dlm);
			arr[i] = ft_substr(s, 0, sublength);
			if (!arr[i])
				return (0);
			s += sublength;
			++i;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		arrsize;
	char	**arr;

	if (!s)
		return (NULL);
	arrsize = getarrlength(s, c) + 1;
	arr = malloc(sizeof(char *) * arrsize);
	if (arr)
	{
		--arrsize;
		arr[arrsize] = NULL;
		if (!fillarr(arr, s, c))
		{
			arrsize = 0;
			while (arr[arrsize])
			{
				free(arr[arrsize]);
				++arrsize;
			}
			free(arr);
			return (NULL);
		}
		return (arr);
	}
	return (NULL);
}
