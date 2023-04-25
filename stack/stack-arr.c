#define MAX 100
#include <stdio.h>
#include <stdlib.h>
int stack[MAX], top = -1, choice, num;

void push(void);
int pop(void);
void display(void);

void main() {
    while(choice != 4){
        printf("Enter your choice: \n1. Push\n2. Pop\n3. Display\n4. Exit\t");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            
            case 2:
                int item = pop();
                printf("%d deleted\n", item);
                break;
                
            case 3:
                display();
                printf("\n");
                break;
            
            case 4:
                printf("Exiting....");
                break;
                
            default:
                printf("Enter correct choice");
        }
    }
}
void push() {
    if (top > MAX - 1){
        printf("Overflow");
        return;
    }
    printf("Enter the number you want to push: ");
    scanf("%d", &num);
    top++;
    stack[top] = num;
}

int pop(){
    if(top == -1){
        printf("Underflow");
        return;
    }
    int item;
    item = stack[top];
    top--;
    return item;
}
void display() {
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    if(top == -1){
        printf("Underflow");
        return;
    }
}
