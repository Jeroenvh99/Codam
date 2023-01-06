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

t_ps_list	*ps_lstnew(int *num, int index);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
void		ps_lstclear(t_ps_list **lst, void (*del)(void *));
void		ps_lstdelone(t_ps_list *lst, void (*del)(void *));
void 		printlist(t_ps_list *head);
int 		lstsearch(t_ps_list *lst, int *num);
void		del(void *node);
int     	issorted(t_ps_list *lst);
int 		loadlist(int argc, char **argv, t_ps_list **a);

void    push_a(t_ps_list *a, t_ps_list *b);
void    push_a(t_ps_list *a, t_ps_list *b);
void    swap_a(t_ps_list *a, t_ps_list *b);
void    swap_b(t_ps_list *a, t_ps_list *b);
void    rotate_a(t_ps_list *a, t_ps_list *b);
void    rotate_b(t_ps_list *a, t_ps_list *b);
void    rrotate_a(t_ps_list *a, t_ps_list *b);
void    rrotate_b(t_ps_list *a, t_ps_list *b);
#endif
