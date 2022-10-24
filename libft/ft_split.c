/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:44:31 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/24 15:09:20 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

static int	getarrlength(const char *s, char dlm)
{
	int		i;
	int		count;
	char	prevc;

	i = 0;
	count = 0;
	prevc = dlm;
	while (i == 0 || s[i - 1])
	{
		if ((s[i] == dlm && prevc != dlm) || (!s[i] && prevc != dlm))
			++count;
		prevc = s[i];
		++i;
	}
	return (count);
}

static char	*getword(char *s, int len)
{
	char	*split;
	int		i;

	i = 0;
	split = malloc(len + 1);
	if (!split)
		return (NULL);
	while (len)
	{
		split[i] = *s;
		++s;
		++i;
		--len;
	}
	split[i] = '\0';
	return (split);
}

static char	*getsplit(char **s, char dlm)
{
	int		i;
	char	prevc;
	char	*split;

	i = 0;
	prevc = dlm;
	while (i == 0 || s[0][i - 1])
	{
		if ((s[0][i] == dlm && prevc != dlm) || (!(s[0][i])
			&& prevc != dlm))
		{
			split = getword(s[0], i);
			if (!split)
				return (NULL);
			s[0] += i;
			return (split);
		}
		prevc = s[0][i];
		++i;
	}
	return (NULL);
}

static void	freearr(char **arr, int current)
{
	int	i;

	i = 0;
	while (i < current)
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		arrsize;
	int		i;
	char	**arr;

	if (!s)
		return (NULL);
	arrsize = getarrlength(s, c) + 1;
	arr = malloc(sizeof(char *) * arrsize);
	if (!arr)
		return (NULL);
	arr[arrsize - 1] = NULL;
	i = 0;
	while (i < arrsize - 1)
	{
		while (*s == c)
			++s;
		arr[i] = getsplit((char **)&s, c);
		if (!arr[i])
		{
			freearr(arr, i);
			return (NULL);
		}
		++i;
	}
	return (arr);
}
