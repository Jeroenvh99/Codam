/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:40:58 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/12/21 07:26:36 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	gnl_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		++count;
		++s;
	}
	return (count);
}

char	*extendmem(char *mem, int increment, int i)
{
	char	*newmem;
	int		prevsize;

	if (mem)
	{
		prevsize = gnl_strlen(mem);
		newmem = malloc(prevsize + increment + 1);
		if (!newmem)
			return (free(mem), NULL);
		while (i < prevsize)
		{
			newmem[i] = mem[i];
			++i;
		}
		newmem[prevsize + increment] = '\0';
		free(mem);
	}
	else
	{
		newmem = malloc(increment + 1);
		if (!newmem)
			return (NULL);
		newmem[increment] = '\0';
	}
	return (newmem);
}

int	copytomem(char **mem, char *src, int i, int len)
{
	int	memlen;

	memlen = gnl_strlen(*mem);
	*mem = extendmem(*mem, len, 0);
	if (!*mem)
		return (-2);
	while (src[i])
	{
		if (src[i] == '\n')
		{
			(*mem)[memlen + i] = src[i];
			(*mem)[memlen + i + 1] = '\0';
			return (i);
		}
		else
		{
			(*mem)[memlen + i] = src[i];
		}
		++i;
	}
	return (-1);
}

void	shiftmem(char *mem, int shiftlen)
{
	int	i;
	int	memlen;

	i = 0;
	memlen = gnl_strlen(mem);
	while (i < memlen + 1 - shiftlen)
	{
		mem[i] = mem[i + shiftlen];
		++i;
	}
}

char	*copyleftstr(char *buffer, int bytesread, int nlindex)
{
	int		i;
	char	*leftstr;

	leftstr = malloc(bytesread - nlindex);
	if (!leftstr)
		return (NULL);
	i = 0;
	while (i < bytesread - nlindex - 1)
	{
		leftstr[i] = buffer[nlindex + i + 1];
		++i;
	}
	leftstr[bytesread - nlindex - 1] = '\0';
	return (leftstr);
}
