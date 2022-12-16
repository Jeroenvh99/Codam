/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:39:52 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/12/16 13:28:45 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"

int	gnl_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		++count;
		++s;
	}
	return (count);
}

char	*extendmem(char *mem, int increment)
{
	char	*newmem;
	int		prevsize;
	int		i;

	if (mem)
	{
		prevsize = gnl_strlen(mem);
		newmem = malloc(prevsize + increment + 1);
		i = 0;
		while (i < prevsize)
		{
			newmem[i] = mem[i];
			++i;
		}
		newmem[prevsize + increment] = '\0';
	}
	else
	{
		newmem = malloc(increment + 1);
		newmem[increment] = '\0';
	}
	return (newmem);
}

int	copytomem(char *mem, char *src, int i, int len)
{
	int	nl;
	int	memlen;

	nl = 0
	memlen = gnl_strlen(mem) - len;
	while (src[i])
	{
		mem[(memlen + i) - 1] = src[i];
		if (src[i] == '\n')
		{
			mem[(memlen + i) - 1] = src[i];
			return (i);
		}
		++i;
	}
	return (0);
}

void	shiftmem(char *mem, int shiftlen)
{
	int	i;
	int	memlen;

	i = 0;
	memlen = gnl_strlen(mem);
	while (i <= memlen)
	{
		mem[i] = mem[i + shiftlen];
		++i;
	}
}

char	*get_next_line(int fd)
{
	static char	*leftstr;
	char		*buffer[BUFFER_SIZE + 1];
	char		*newline;
	int			bytesread;
	int			nlindex;

	newline = NULL;
	if (leftstr)
	{
		leftstrlength = gnl_strlen(leftstr);
		newline = extendmem(newline, leftstrlength);
		nlindex = copytomem(newline, leftstr, 0, leftstrlength);
		if (nlindex)
		{
			shiftmem(leftstr, nlindex + 1);
			return (newline);
		}
	}
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == 0)
		{
			if (newline)
				free(newline);
			if (leftstr)
				free(leftstr);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		newline = extendmem(newline, bytesread);
		nlindex = copytomem(newline, buffer, 0, bytesread);
		if (nlindex)
		{
			leftstr = extendmem(leftstr, (bytesread - nlindex));
			copytomem(leftstr, buffer, nlindex + 1, (bytesread - nlindex));
			return (newline);
		}
	}
}
