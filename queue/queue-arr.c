#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void enqueue(int [], int *, int*, int);
void dequeue(int [], int *, int *);
void display(int [], int, int);
int main() {
    int queue[MAX], n, choice, item;
    int front = -1, rear = -1;
    while(1){
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\t");
        scanf("%d", &choice);
        switch(choice){
            
            case 1:
                printf("Enter the element you want to enter: ");
                scanf("%d", &item);
                enqueue(queue, &front, &rear, item);
                break;
            
            case 2:
                dequeue(queue, &front, &rear);
                break;
            
            case 3:
                display(queue, front, rear);
                break;
            
            default:
                exit(0);
        }
    }
    
    return 0;
}

void enqueue(int queue[], int *front, int *rear, int element) {  
    if((*front) == -1 && (*rear) == -1) {  
        *front = 0;  
        *rear = 0;  
        queue[*rear] = element;  
    }  
    else if(((*rear) + 1) % MAX == (*front)) {  
        printf("Queue is overflow..");  
    }  
    else  
    {  
        (*rear) = ((*rear) + 1) % MAX;
        queue[*rear] = element;
    }  
}  

void dequeue(int queue[], int *front, int *rear) {  
    if((*front) == -1 && (*rear) == -1) {  
        printf("\nQueue is underflow..");  
    }  
     else if(*front == *rear) {  
       printf("\nThe dequeued element is %d\n", queue[*front]);  
       *front =-1;  
       *rear =-1;  
    }   
    else {  
        printf("\nThe dequeued element is %d", queue[*front]);  
        *front = ((*front) + 1) % MAX;  
    }  
} 
void display(int queue[], int front, int rear){
    int i = front;
    while(i <= rear){
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;    
    }
}
