/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/16 22:01:09 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp1;
	int temp2;

	i = 0;
	while (i < size - 1)
	{
		temp1 = tab[i];
		temp2 = tab[i + 1];
		if (temp1 > temp2)
		{
			tab[i] = temp2;
			tab[i + 1] = temp1;
			i = 0;
		}
		i++;
	}
}

int main(){
    int arr[8] = {34, 23, 643, 98, 45, 12, -9, 36};
    ft_sort_int_tab(arr, 8);
    int i = 0;
    while (i < 8){
        printf("The value on index %i is %i\n", i, arr[i]);
        i++;
    }
    return 0;
}