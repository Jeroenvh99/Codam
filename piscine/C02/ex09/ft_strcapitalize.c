/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcapitalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/24 18:17:27 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	formatletters(int i, int j, char *str)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] += 32;
	if (j == 1)
	{
		if (i == 0)
			str[i] -= 32;
		else if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
			str[i] -= 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
				&& str[i] <= 'Z'))
		{
			j++;
			formatletters(i, j, str);
		}
		else
		{
			j = 0;
		}
		i++;
	}
	return (str);
}

// int main()
// {
// 	char s[] = "salut, coMMEnt tu vas ? 42mots quarante-deux; cinquante+et+un";
// 	ft_strcapitalize(s);
// 	printf("%s", s);
// 	return 0;
// }