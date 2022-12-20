/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:39:52 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/12/20 18:55:50 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"
#include<fcntl.h>
#include<stdio.h>

int	getstart(char **newline, char **leftstr)
{
	int	nlindex;

	nlindex = copytomem(newline, *leftstr, 0, gnl_strlen(*leftstr));
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

int	processbuffer(char **newline, char *buffer, char **leftstr, int bytesread)
{
	int	nlindex;

	if (bytesread == -1)
	{
		free(*leftstr);
		*leftstr = NULL;
		free(*newline);
		*newline = NULL;
		return (1);
	}
	if (bytesread == 0)
		return (1);
	buffer[bytesread] = '\0';
	nlindex = copytomem(newline, buffer, 0, bytesread);
	if (nlindex == -2)
	{
		free(*leftstr);
		free(*newline);
		return (1);
	}
	if (nlindex > -1)
	{
		if (nlindex < bytesread - 1)
		{
			*leftstr = copyleftstr(buffer, bytesread, nlindex);
			if (!*leftstr)
			{
				free(*newline);
				return (1);
			}
		}
		return (1);
	}
	return (0);
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
		if (processbuffer(&newline, buffer, &leftstr, bytesread) == 1)
			break ;
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