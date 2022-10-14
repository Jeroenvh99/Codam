/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:55:27 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/10 11:48:32 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i == 0 || (s1[i - 1] && s2[i - 1])) && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else
		{
			++i;
		}
	}
	return (0);
}

// int main(){
// 	char s0[8] = "asbfgbfg";
// 	char s1[8] = "asbfgbfg";
// 	char s2[8] = "asbkubfg";
// 	char s3[8] = "asbfgb";
// 	printf("%i\n", (ft_strncmp(s0, s1, 8)));
// 	printf("%i\n", (ft_strncmp(s0, s2, 8)));
// 	printf("%i\n", (ft_strncmp(s0, s3, 8)));
// 	printf("%i\n", (ft_strncmp(s0, s1, 3)));
// 	printf("%i\n", (ft_strncmp(s0, s2, 3)));
// 	printf("%i\n", (ft_strncmp(s0, s3, 3)));
// 	printf("%i\n", ft_strncmp("hello", "hel", 4));
// 	return 0;
// }
