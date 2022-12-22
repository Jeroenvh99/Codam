/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:39:52 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/12/22 07:55:10 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<limits.h>
#include"get_next_line.h"

static int	getstart(char **newline, char **leftstr)
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

static int	checkreaderror(int bytesread, char **newline, char **leftstr)
{
	if (bytesread == -1)
	{
		free(*leftstr);
		*leftstr = NULL;
		free(*newline);
		*newline = NULL;
		return (1);
	}
	return (0);
}

static int	processbuffer(char **newline, char *buffer, char **leftstr,
	int bytesread)
{
	int	nlindex;

	if (checkreaderror(bytesread, newline, leftstr) == 1)
		return (1);
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
	else if (nlindex > -1)
	{
		if (nlindex < bytesread - 1)
		{
			*leftstr = copyleftstr(buffer, bytesread, nlindex);
			if (!*leftstr)
				free(*newline);
		}
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*leftstr[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	int			bytesread;
	int			nlindex;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE == 0)
		return (NULL);
	newline = NULL;
	bytesread = 1;
	if (leftstr[fd])
	{
		nlindex = getstart(&newline, &leftstr[fd]);
		if (nlindex == 0)
			return (NULL);
		else if (nlindex == 2)
			bytesread = 0;
	}
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (processbuffer(&newline, buffer, &leftstr[fd], bytesread) == 1)
			break ;
	}
	return (newline);
}

// int main(){
// 	int fd = open("get_next_line.c", O_RDONLY);
// 	char *str = "";
// 	while (str){
// 		str = get_next_line(fd);
// 		printf("nl: %s", str);
// 		free(str);
// 	}
// 	return (0);
// }