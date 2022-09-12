/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_int_tab.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/15 13:59:24 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size - 1 - i)
	{
		j = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = j;
		i++;
	}
}

// int main(){
// 	int arr[] = {3, 6, 7, 35, 735, 67547};
// 	int i = 0;
// 	ft_rev_int_tab(arr, 6);
// 	while (i < 6){
// 		printf("The number on position %i is: %i\n", i, arr[i]);
// 		i++;
// 	}
// 	return 0;
// }