#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
    int info;
    struct nodeType *prev, *next;
}node;

node *head = NULL;
node *tail = NULL;

void insertAtBeg(node **, node **, int);
void insertAtEnd(node **, node **, int);
void inorderTraverse(node *);

int main() {
    int choice, item;
    while(1){
        printf("Enter the operation you want to perform:\n1. Insert at Beginning\n2. Insert at Ending\n3. Inorder Traversal ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &item);
                insertAtBeg(&head, &tail, item);
                break;
            
            case 2:
                printf("Enter the data: ");
                scanf("%d", &item);
                insertAtEnd(&head, &tail, item);
                break;
                
            case 3:
                inorderTraverse(head);
                printf("NULL/n");
                break;
        }
    }
    return 0;
}

void insertAtBeg(node **head, node **tail, int item){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr -> info = item;
    if(*head == NULL){
        ptr -> next = ptr -> prev = NULL;
        *head = *tail = ptr;
    } else{
        ptr -> next = *head;
        (*head) -> prev = ptr;
        ptr -> prev = NULL;
        *head = ptr;
    }
}
void inorderTraverse(node *head){
    if (head == NULL){
        printf("Empty");
        return;
    }
    while(head != NULL){
        printf("%d -> ", head -> info);
        head = head ->next;
    }
}
void insertAtEnd(node **head, node **tail, int item){
    node *ptr = (node *)malloc(sizeof(node));
    ptr -> info = item;
    if(*head == NULL){
        ptr -> next = ptr -> prev = NULL;
        *head = *tail = ptr;
        return;
    }
    (*tail) -> next = ptr;
    ptr -> prev = *tail;
    ptr -> next = NULL;
    *tail = ptr;
}
