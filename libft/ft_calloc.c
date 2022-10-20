/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 09:39:33 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/19 20:14:34 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	size *= count;
	mem = malloc(size);
	if (mem)
	{
		ft_memset(mem, 0, size);
		return (mem);
	}
	return (NULL);
}
