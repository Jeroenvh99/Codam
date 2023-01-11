/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 11:57:45 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/10 15:46:40 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include"./../libft.h"

t_list	*swap_a(t_list *a);
t_list	*swap_b(t_list *b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
t_list	*rotate_a(t_list *a);
t_list	*rotate_b(t_list *a);
t_list	*rrotate_a(t_list *a);
t_list	*rrotate_b(t_list *b);

int		issorted(t_list *lst);
int		loadlist(int argc, char **argv, t_list **a);
void	del(void *node);
void	printlist(t_list *head);
#endif