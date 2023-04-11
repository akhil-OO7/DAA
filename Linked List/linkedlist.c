#include <stdio.h>
#include <stdlib.h>
typedef struct nodeType{
    int info;
    struct nodeType *next;
}node;
node *head = NULL;

void insertAtBeg(node **, int);
void traverse(node *);
void insertAtEnd(node **, int);
void deleteFromBeg(node **);
void deleteFromEnd(node *);

int main() {
    int choice, item, i = 0;
    while(1){
    printf("Enter your choice: \n1. Insert at Beginning\n2. Insert at Ending\n3. Traverse\n4. Deletion from Beginning\n5. Delete From Ending\n6. Exit ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the data: ");
            scanf("%d", &item);
            insertAtBeg(&head, item);
            break;
        
        case 2:
            printf("Enter the data: ");
            scanf("%d", &item);
            insertAtEnd(&head, item);
            break;
        
        case 3:
            traverse(head);
            printf("NULL\n");
            break;
        
        case 4:
            deleteFromBeg(&head);
            break;
        
        case 5:
            deleteFromEnd(head);
            
        default:
            exit(0);
        }
    };
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

void insertAtEnd(node **head, int item){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr -> info = item;
    node *tmp = *head;
    if (*head == NULL){
        *head = ptr;
        return;
    }
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = ptr;
}

void traverse(node * head){
    while(head != NULL){
        printf("%d->", head -> info);
        head = head -> next;
    }
}

void deleteFromBeg(node **head){
    node *temp = *head;
    *head = temp -> next;
    temp -> next = NULL;
    free(temp);
}

void deleteFromEnd(node *head){
    node *tmp;
    while(head -> next != NULL){
        tmp = head;
        head = head ->next;
    }
    tmp -> next = NULL;
    free(head);
}
