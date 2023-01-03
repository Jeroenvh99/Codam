#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include"libft.h"

int     loadlist(int argc, char **argv, t_list **a);
void    printlist(t_list *head);
int     lstsearch(t_list *lst, int *content);
void	del(void *node);
int     issorted(t_list *lst);

#endif