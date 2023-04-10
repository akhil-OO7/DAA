#include <stdio.h>
#include <stdlib.h>
typedef struct nodeType{
    int info;
    struct nodeType *next;
}node;
node *head = NULL;
void insertAtBeg(node **, int);
void traverse(node *);
int main() {
    int choice, item;
    printf("Enter your choice: ");
    switch(choice){
        case 1:
            printf("Enter the data: ");
            scanf("%d", &item);
            insertAtBeg(node **head, item);
            break;
        
        case 2:
            traverse(node *head);
            break;
    }

    return 0;
}
void insertAtBeg(node **head, item){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr -> info = item;
    if(head == NULL)
        *head = ptr;
    else
        ptr -> next = *head;
    *head = ptr;
}
void traverse(node * head){
    while(head != NULL){
        printf("%d", head -> info);
        head = head -> next;
    }
}
