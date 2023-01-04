#include<unistd.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include"push_swap.h"

gcc push_swap.c ../libft/ft_lstadd_back.c ../libft/ft_lstnew.c ../libft/ft_lstclear.c ../libft/ft_lstdelone.c ../libft/ft_lstlast.c input_utils.c list_utils.c ../libft/ft_printf.c ../libft/ft_printf_utils.c ../libft/ft_num_utils.c ../libft/ft_format_utils.c ../libft/ft_hex_utils.c ../libft/ft_calloc.c ../libft/ft_strdup.c ../libft/ft_strchr.c ../libft/ft_memset.c ../libft/ft_strlen.c ../libft/ft_strnstr.c ../libft/ft_strncmp.c

int main(int argc, char **argv)
{
    t_ps_list  *a;
    t_ps_list  *b;

    a = NULL;
    b = NULL;
    if (argc > 1 && argc - 1 <= UINT_MAX)
    {
        if (loadlist(argc, argv, &a) == 0)
        {
            write(2, "error\n", 6);
            return (1);
        }
        if (issorted(a))
            return (0);
        a = unsignlist(a);
        printlist(a);
    }
    return (0);
}