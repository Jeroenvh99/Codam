/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 15:26:42 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/03/21 16:28:45 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

char	*check_double(char *s)
{
	++s;
	while (*s)
	{
		if (*s == 34)
			return (s + 1);
		else
			++s;
	}
	return (NULL);
}

char	*check_single(char *s)
{
	++s;
	while (*s)
	{
		if (*s == 39)
			return (s + 1);
		else
			++s;
	}
	return (NULL);
}

static int	skip_single(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == 39)
			break ;
		else
			++i;
	}
	return (i);
}

static int	skip_double(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == 34)
			break ;
		else
			++i;
	}
	return (i);
}

int	skip_quotes(char ***s, int *quotes, int i)
{
	if (s[0][0][i] == 39)
	{
		++(*quotes);
		++s[0][0];
		i = skip_single(s[0][0], i);
	}
	if (s[0][0][i] == 34)
	{
		++(*quotes);
		++s[0][0];
		i = skip_double(s[0][0], i);
	}
	return (i);
}
