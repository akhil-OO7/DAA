#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
    int info;
    struct nodeType *prev, *next;
}node;

node *head = NULL;
node *tail = NULL;

void insertAtBeginning(node **, node**, int);
void inorderTraversal(node *head);
int main() {
    int choice, item;
    while(1){
        printf("Enter the operation you want to perform:\n1. Insert at Beginning\n2. Inorder Traversal");
        switch(choice){
            case 1: 
                printf("Enter the data you want to enter: ");
                scanf("%d", &item);
                insertAtBeginning(&head, &tail, item);
                break;
                
            case 2:
                inorderTraversal(head);
                break;
                
            default:
                exit(0);
                break;
        }
    }
    return 0;
}

void insertAtBeginning(node **head, node **tail, int item){
    node *ptr = (node *)malloc(sizeof(node));
    ptr -> info = item;
    if(*head == NULL){
        *head = *tail = ptr;
        return;
    }
    ptr -> next = *head;
    *head -> prev = ptr;
    *head = ptr;
}
