/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:39:52 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/12/20 14:00:23 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"
#include<fcntl.h>
#include<stdio.h>

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

char	*extendmem(char *mem, int increment)
{
	char	*newmem;
	int		prevsize;
	int		i;

	if (mem)
	{
		prevsize = gnl_strlen(mem);
		newmem = malloc(prevsize + increment + 1);
		if (!newmem)
		{
			free(mem);
			return (NULL);
		}
		i = 0;
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
		i = 0;
		while (i < increment)
		{
			newmem[i] = '0';
			++i;
		}
		newmem[increment] = '\0';
	}
	return (newmem);
}

int	copytomem(char **mem, char *src, int i, int len)
{
	int	memlen;

	memlen = gnl_strlen(*mem);
	*mem = extendmem(*mem, len);
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

int	getstart(char **newline, char **leftstr)
{
	int	nlindex;

	nlindex = copytomem(newline, *leftstr, 0, gnl_strlen(*leftstr));
	// printf("left: %s\n", *leftstr);
	// printf("index: %i\n", nlindex);
	if (nlindex == -2)
	{
		free(*leftstr);
		free(*newline);
		return (0);
	}
	if (nlindex > -1)
	{
		shiftmem(*leftstr, nlindex + 1);
		if (*leftstr[0] == '\0')
		{
			free(*leftstr);
			*leftstr = NULL;
		}
		return (2);
	}
	else
	{
		free(*leftstr);
		*leftstr = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftstr;
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	int			bytesread;
	int			nlindex;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	newline = NULL;
	bytesread = 1;
	if (leftstr)
	{
		nlindex = getstart(&newline, &leftstr);
		if (nlindex == 0)
			return (NULL);
		else if (nlindex == 2)
			bytesread = 0;
	}
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(leftstr);
			leftstr = NULL;
			free(newline);
			newline = NULL;
			break ;
		}
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		nlindex = copytomem(&newline, buffer, 0, bytesread);
		if (nlindex == -2)
		{
			free(leftstr);
			free(newline);
			return (NULL);
		}
		if (nlindex > -1)
		{
			if (nlindex < bytesread - 1)
			{
				leftstr = copyleftstr(buffer, bytesread, nlindex);
				if (!leftstr)
				{
					free(newline);
					return (NULL);
				}
			}
			break ;
		}
	}
	return (newline);
}

// int main(){
// 	int fd = open("in.txt", O_RDONLY);
// 	char *str = "";
// 	while (str){
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }