#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1;
int rear = -1;
void enqueue(int [], int, int, int, int);
int main() {
    int queue[MAX], n, choice, item;
    while(1){
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Exit\t");
        scanf("%d", &choice);
        switch(choice){
            
            case 1:
                printf("Enter the element you want to enter: ");
                scanf("%d", &item);
                enqueue(queue, front, rear, MAX, item);
                break;
            
            case 2:
                display(queue, front, rear);
                break;
            
            default:
                exit(0);
        }
    }
    
    return 0;
}
void enqueue(int queue[], int front, int rear, int n, int item) {
    
    if((front == 0 && rear == n -1)|| (front == rear + 1)){
        printf("Overflow");
    }
    else {
        if(front == -1)
            front = rear = 0;
        else {
            if (rear = n - 1)
                rear = 0;
            else
                rear++;
        }
    }
    queue[rear] = item;
}
void display(int queue[], int front, int rear){
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
}
