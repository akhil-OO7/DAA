#include<stdio.h>
#include<stdlib.h>
typedef struct nodeType{
    int info;
    struct nodeType *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

void insert(queue **, queue **,int);
void deletion(queue **);
void display(queue *);

void main() {
    int item, choice = 0;     
    printf("\n*********Queue operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4) {  
        printf("\n\nChoose one from the below options...\n");  
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");  
        printf("\nEnter your choice \t");        
        scanf("%d",&choice);  
        switch(choice) {
            case 1:
                printf("Enter the item you want to push: ");
                scanf("%d", &item);
                insert(&front, &rear, item);
                break;
            
            case 2:
                deletion(&front);
                break;
            
            case 3:
                display(front);
                break;
            
            case 4:
                printf("Exiting...");
                break;
            
            default:
                printf("\nWrong choice entered\n");
        };   
    }
}

void insert(queue **front, queue **rear, int item) {
    queue *ptr = (queue *)malloc(sizeof(queue));
    if(ptr == NULL) {
        printf("\nOverflow\n");
        return;
    }
    ptr -> info = item;
    ptr -> next = NULL;
    if(*front == NULL){
        *front = *rear = ptr;
    }
    else {
        (*rear) -> next = ptr;
        *rear = ptr;
    }
    printf("\nItem Inserted\n");
}

void deletion(queue **front) {
    int item;
    queue *ptr;
    if(*front == NULL){
        printf("Underflow...");
        return;
    }
    item = (*front) -> info;
    ptr = *front;
    *front = (*front) -> next;
    free(ptr);
    printf("\nItem Deleted: %d\n", item);
}

void display(queue *front){
    if(!front){
        printf("\nQueue is empty: \n");
    }
    while(front){
        printf("%d -> ",front -> info);
        front = front -> next;
    }
}
