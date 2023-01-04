#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include"libft.h"

typedef struct s_ps_list
{
	int			        *num;
    int                 index;
	struct s_ps_list	*prev;
	struct s_ps_list	*next;
}	t_ps_list;

int     loadlist(int argc, char **argv, t_list **a);
void    printlist(t_list *head);
int     lstsearch(t_list *lst, int *content);
void	del(void *node);
int     issorted(t_list *lst);

void    push_a(t_ps_list *a, t_ps_list *b);
void    swap_b(t_ps_list *a, t_ps_list *b);
void    push_a(t_ps_list *a, t_ps_list *b);
void    push_b(t_ps_list *a, t_ps_list *b);
void    rotate_a(t_ps_list *a, t_ps_list *b);
void    rotate_b(t_ps_list *a, t_ps_list *b);
void    rreverse_a(t_ps_list *a, t_ps_list *b);
void    rreverse_b(t_ps_list *a, t_ps_list *b);
#endif