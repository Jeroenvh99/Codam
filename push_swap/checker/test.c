#include<stdlib.h>
#include<stdio.h>
#include"./../libft.h"
#include"checker.h"

t_list	*rrotate_a(t_list *a)
{
	t_list	*current;
	t_list	*newhead;

	if (!(a && a->next))
		return (NULL);
	current = a;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	a->prev = current;
	current->next = a;
	newhead = current;
	return (newhead);
}

int main(){
	t_list *a;
	t_list *b;
	int i;
	int *num;
	a = NULL;
	b = NULL;
	i = 0;
	while (i < 4){
		num = (int *)malloc(sizeof(int));
		*num = i;
		ft_lstadd_back(&a, ft_lstnew(num));
		++i;
	}
	a = rrotate_a(a);
	printlist(a);
	// printf("b\n");
	// printlist(b);
}