/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_word.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dligthar <dligthar@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/27 16:35:30 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char    *last_word(char *str)
{
    int len;
    int begin;

    len = ft_strlen(str) - 1;
    begin = 0;
    while (len >= 0)
    {
        if ((str[len] >= 'a' && str[len] <= 'z') || (str[len] >= 'A' && str[len] <= 'Z'))
            begin = 1;
        if (begin && ((str[len] >= 'a' && str[len] <= 'z') || (str[len] >= 'A' && str[len] <= 'Z')))
            return (&(str[len + 1]));
        len--;
    }
    return NULL;
}

int main()
{
    char str[] = "maten er her";
    char *c;

    c = last_word(str);
    printf("%s", c);
    return 0;
}