/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:57:57 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 11:14:11 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelength;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	needlelength = ft_strlen(needle);
	while (*haystack && i < len && len - i > needlelength - 1)
	{
		if (!ft_strncmp(haystack, needle, needlelength))
			return ((char *)haystack);
		++i;
		++haystack;
	}
	return (NULL);
}

// int main(){
// 	char c[21] = "dfjoirfjrehgudfragtr";
// 	char n0[7] = "";
// 	char n1[7] = "udfr";
// 	char n2[7] = "udcr";
// 	printf("%s\n", ft_strnstr(c, n0, 16));
// 	printf("%s\n", ft_strnstr(c, n1, 16));
// 	printf("%s", ft_strnstr(c, n2, 16));
// 	return 0;
// }
