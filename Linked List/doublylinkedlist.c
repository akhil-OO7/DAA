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
void postorderTraverse(node *);
void deleteFromBeg(node **);
void deleteFromEnd(node **);


int main() {
    int choice, item;
    while(1){
        printf("Enter the operation you want to perform:\n1. Insert at Beginning\n2. Insert at Ending\n3. Inorder Traversal\n4. Post Order Traversal\n5. Delete from Beginning\n6. Delete from Ending ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the data: ");
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
                printf("NULL\n");
                break;
            
            case 4:
                postorderTraverse(tail);
                printf("NULL\n");
                break;
            
            case 5:
                deleteFromBeg(&head);
                break;
                
            case 6:
                deleteFromEnd(&tail);
                break;
            
            default:
                exit(0);
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

void inorderTraverse(node *head){
    if (head == NULL){
        return;
    }
    while(head != NULL){
        printf("%d -> ", head -> info);
        head = head ->next;
    }
}

void postorderTraverse(node *tail){
    if (tail == NULL){
        return;
    }
    while(tail != NULL){
        printf("%d -> ", tail -> info);
        tail = tail -> prev;
    }
}

void deleteFromBeg(node **head){
    if(*head == NULL){
        printf("Underflow\n");
        return;
    }
    if((*head) -> next == NULL){
        free(*head);
        (*head) = NULL;
        return;
    }
    node *tmp;
    tmp = *head;
    *head = (*head) -> next;
    (*head) -> prev = NULL;
    free(tmp);
}

void deleteFromEnd(node **tail){
    if(*tail == NULL){
        printf("Underflow\n");
        return;
    }
    if((*tail) -> prev == NULL){
        free(*tail);
        (*tail) = NULL;
        return;
    }
    node *tmp;
    tmp = *tail;
    *tail = (*tail) -> prev;
    (*tail) -> next = NULL;
    free(tmp);
}
