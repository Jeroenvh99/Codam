/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:14:20 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 11:23:50 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include"libft.h"

t_list	*ps_lstnew(int *num, int index);
void	ps_lstadd_back(t_list **lst, t_list *new);
void	ps_lstclear(t_list **lst, void (*del)(void *));
void	ps_lstdelone(t_list *lst, void (*del)(void *));
void	printlist(t_list *head);
int		lstsearch(t_list *lst, int *num);
void	del(void *node);
int		issorted(t_list *lst);
int		loadlist(int argc, char **argv, t_list **a);

void	push_a(t_list **a, t_list *b);
void	push_b(t_list *a, t_list **b);
t_list	*swap_a(t_list *a);
t_list	*swap_b(t_list *b);
t_list	*rotate_a(t_list *a);
t_list	*rotate_b(t_list *b);
t_list	*rrotate_a(t_list *a);
t_list	*rrotate_b(t_list *b);
#endif
