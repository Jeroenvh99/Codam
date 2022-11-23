#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct mlx_list
{
	void			*content;
	struct mlx_list	*next;
	struct mlx_list	*prev;
}	mlx_list_t;

int comp(void *node, void *value)
{
	return (memcmp(((mlx_list_t *)node)->content, value, strlen(value)));
}

/**
 * Removes the specified content from the list, if found.
 * Also fixes any relinking that might be needed.
 *
 * @param[in] lst The list
 * @param[in] comp Function to check if the content and value are the same.
 * @returns The removed element, clean up as you wish.
 */
mlx_list_t* mlx_lstremove(mlx_list_t** lst, void* value, int (*comp)(void*, void*))
{
	mlx_list_t* lstcpy = *lst;

	while (lstcpy && !comp(lstcpy->content, value))
		lstcpy = lstcpy->next;
	if (lstcpy == NULL)
		return (NULL);
	if (lstcpy == *lst)
		*lst = lstcpy->next;
	if (lstcpy->next != NULL)
		lstcpy->next->prev = lstcpy->prev;
	if (lstcpy->prev != NULL)
		lstcpy->prev->next = lstcpy->next;
	return (lstcpy);
}

void printlist(mlx_list_t *head){
	while (head){
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

mlx_list_t* mlx_lstnew(void* content)
{
	mlx_list_t* out = NULL;

	if ((out = malloc(sizeof(mlx_list_t))))
	{
		out->content = content;
		out->next = NULL;
		out->prev = NULL;
	}
	return (out);
}

mlx_list_t* mlx_lstlast(mlx_list_t* lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void mlx_lstadd_back(mlx_list_t** lst, mlx_list_t* new)
{
	if (!lst || !new)
		return;
	if (!*lst)
		*lst = new;
	else
	{
		mlx_list_t* temp = mlx_lstlast(*lst);
		new->prev = temp;
		temp->next = new;
	}
}

void mlx_lstadd_front(mlx_list_t** lst, mlx_list_t* new)
{
	if (!lst || !new)
		return;
	if ((*lst) != NULL)
		(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

int main(){
	mlx_list_t *head = mlx_lstnew("hello world!");
	mlx_lstadd_back(&head, mlx_lstnew("have a good day"));
	mlx_lstadd_front(&head, mlx_lstnew("enjoy your day"));
	mlx_lstadd_back(&head, mlx_lstnew("have a nice day"));
	mlx_lstadd_front(&head, mlx_lstnew("enjoy your evening"));
	mlx_lstadd_back(&head, mlx_lstnew("have a wonderful day"));
	mlx_lstadd_front(&head, mlx_lstnew("good to see you"));
	mlx_lstadd_back(&head, mlx_lstnew("takk for sist"));
	mlx_lstadd_front(&head, mlx_lstnew("god tur!"));
	mlx_lstadd_back(&head, mlx_lstnew("have a nice trip"));
	mlx_lstadd_front(&head, mlx_lstnew("enjoy your holiday"));
	mlx_lstadd_back(&head, mlx_lstnew("have a nice cup of hot chocolate"));
	mlx_lstadd_front(&head, mlx_lstnew("enjoy your drink"));
	mlx_lstadd_back(&head, mlx_lstnew("have a break"));
	mlx_lstadd_front(&head, mlx_lstnew("enjoy your dinner"));
	mlx_lstadd_back(&head, mlx_lstnew("eet smakelijk"));
	mlx_lstadd_front(&head, mlx_lstnew("enjoy your meal"));
	printlist(head);
	char value[14] = "eet smakelijk";
	mlx_lstremove(&head, value, comp);
	printlist(head);
	return 0;
}