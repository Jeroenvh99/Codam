/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:50:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/13 11:51:41 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		srclen;
	int		shift;

	i = 0;
	srclen = ft_strlen(src);
	if (!(dst - src > srclen || src - dst > srclen))
	{
		shift = srclen - (dst - src);
		dst -= shift;
	}
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}

int main()
{
	char a[] = "hello";
	char b[] = "hiagain";
	ft_memmove(&a, &b, 2);
	printf("The contents of string a are:%s\n", a);
	printf("The contents of string b are:%s", b);
	return 0;
}
