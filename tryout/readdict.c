#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct node {
    char* word;
    double number;
    struct node *next;
} node_t;

void printlist(node_t *head){
    while (head){
        printf("number: %lf, word: %s ", head->number, head->word);
        head = head->next;
    }
}

void freelist(node_t *head){
    while (head->next){
        node_t *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}

void insert(node_t *newnode, node_t *head){
    while (head->number <= newnode->number && head->next){
        head = head->next;
    }
    if (head->next){
        newnode->next = head->next;
        head->next = newnode;
    }
    else{
        newnode->next = NULL;
        head->next = newnode;
    }
}

void readdict(node_t *head){
    int fd;
    fd = open("numbers.dict", O_RDONLY);
    int status = 1;
    char stringtoparse[50];
    char c;
    int pos = 0;
    node_t *newnode = (node_t*)malloc(sizeof(node_t));

    while (status){
        status = read(fd, &c, 1);
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            stringtoparse[pos] = c;
            ++pos;
        }
        if (c == ':'){
            newnode->number = atof(stringtoparse);
            pos = 0;
        }
        if (c == '\n'){
            newnode->word = malloc(pos + 1);
            newnode->word = stringtoparse;
            printf("number: %lf, word: %s \n", newnode->number, newnode->word);
            //insert(newnode, head);
            for (pos = 0; pos < 50; pos++){
                stringtoparse[pos] = '\0';
            }
            pos = 0;
        }
    }
    close(fd);
}

int main(){
    node_t *head = (node_t*)malloc(sizeof(node_t));
    head->next = NULL;
    readdict(head);
    printlist(head);
    freelist(head);
    head = NULL;
    return 0;
}