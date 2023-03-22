/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 19:07:33 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/03/21 17:51:20 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"pipex.h"

static int	getarrlength(char *s, char dlm)
{
	int		count;
	char	prevc;

	count = 0;
	prevc = dlm;
	while (*s)
	{
		if (*s == 39)
			s = check_single(s);
		if (*s == 34)
			s = check_double(s);
		prevc = *(s - 1);
		if (*s == dlm && prevc != dlm)
			++count;
		prevc = *s;
		if (!*s)
			break ;
		++s;
	}
	if (prevc != dlm)
		++count;
	return (count);
}

static char	*getsplit(char **s, char dlm)
{
	int		i;
	int		quotes;
	char	prevc;
	char	*split;

	i = 0;
	quotes = 0;
	prevc = dlm;
	while (i == 0 || s[0][i - 1])
	{
		i = skip_quotes(&s, &quotes, i);
		prevc = s[0][i];
		++i;
		if ((s[0][i] == dlm && prevc != dlm) || (!(s[0][i])
			&& prevc != dlm))
		{
			split = ft_substr(s[0], 0, i - quotes);
			if (!split)
				return (NULL);
			s[0] += i;
			return (split);
		}
	}
	return (NULL);
}

static void	freearr(char **arr, int i)
{
	--i;
	while (i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		--i;
	}
	free(arr);
	arr = NULL;
}

char	**split_args(char *s, char c)
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
		arr[i] = getsplit(&s, c);
		if (!arr[i])
		{
			freearr(arr, i);
			return (NULL);
		}
		++i;
	}
	return (arr);
}
