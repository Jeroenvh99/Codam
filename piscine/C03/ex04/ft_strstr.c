/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/28 17:42:28 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		len;
	int		i;
	int		j;
	char	*substr;

	len = ft_strlen(to_find);
	i = 0;
	j = 0;
	substr = str;
	while (str[i])
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		if (j == len - 1)
		{
			substr = &(str[i - (j - 1)]);
			break ;
		}
		else
			substr = NULL;
		i++;
	}
	return (substr);
}

// int main(){
// 	char big[] = "bonjour mon ami";
// 	char small[] = "mon";
// 	char	*str;
// 	str = ft_strstr(big, small);
// 	printf("%s", str);
// 	return 0;
// }