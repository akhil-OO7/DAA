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
    int choice, item, i = 0;
    while(1){
    printf("Enter your choice: \n1. Insert at Beginning\n2. Traverse\n3. Exit ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the data: ");
            scanf("%d", &item);
            insertAtBeg(&head, item);
            break;
        
        case 2:
            traverse(head);
            break;
        
        default:
            exit(0);
        }
    }
    printf("Program End");
    return 0;
}
void insertAtBeg(node **head, int item){
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
        printf("%d->", head -> info);
        head = head -> next;
    }
}
