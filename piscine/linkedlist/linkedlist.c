/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/28 11:38:03 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    int key;
    struct node *next;
} node_t;

void printlist(node_t *head){
    while (head){
        printf("key: %i, data: %i ", head->key, head->data);
        head = head->next;
    }
}

void push(node_t *head, int key, int data)
{
    node_t *current = head;
    while (current->next){
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->key = key;
    current->next->data = data;
    current->next->next = NULL;
}

void freelist(node_t *head){
    while (head->next){
        node_t *next = head->next;
        free(head);
        head = next;
    }
}

int main(){
    struct node *head = (node_t *)malloc(sizeof(node_t));;
    head->key = 76;
    head->data = 567;
    head->next = NULL;
    
    push(head, 5, 2324235);
    push(head, 3, 64456);
    push(head, 8, 567);
    push(head, 345, 67);
    push(head, 43, 456);
    push(head, 35, 675);
    push(head, 23, 57);
    printlist(head);
    freelist(head);
    head = NULL;
    return 0;
}