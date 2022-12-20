/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:40:52 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/12/20 18:57:59 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

int		gnl_strlen(const char *s);
int		copytomem(char **mem, char *src, int i, int len);
void	shiftmem(char *mem, int shiftlen);
char	*copyleftstr(char *buffer, int bytesread, int nlindex);
char	*get_next_line(int fd);

#endif
