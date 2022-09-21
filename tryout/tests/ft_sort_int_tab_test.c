#include<stdio.h>

void    ft_sort_int_tab(int *tab, int size)
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
        else{
            i++;
        }
    }
}

void is_array_sorted_ascending(int *tab, int size){
    int i = 0;
    while (i < size - 1){
        int s1 = tab[i];
        int s2 = tab[i + 1];
        if (s1 > s2){
            printf("a number in the array is bigger than the next, the sort algorithm didn't function properly\n");
            return;
        }
        i++;
    }
    printf("no number in the array is bigger than the next, the sort algorithm worked properly\n");
}

int main(){
    int arr[15] = {-57864, 6578, 4789, -54389, 65756, 567, 23, 34, 23, 643, 98, 45, 12, -9, 36};
    ft_sort_int_tab(arr, 15);
    is_array_sorted_ascending(arr, 15);
    int i = 0;
    while (i < 15){
        printf("The value on index %i is %i\n", i, arr[i]);
        i++;
    }
    return 0;
}