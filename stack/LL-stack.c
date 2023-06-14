#include<stdio.h>
#include<stdlib.h>
typedef struct nodeType{
    int info;
    struct nodeType *next;
}stack;

void push(stack **, int);
void pop(stack **);
void show(stack *);

stack *top = NULL;
void main() {
    int item, choice = 0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4) {  
        printf("\n\nChoose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\nEnter your choice \t");        
        scanf("%d",&choice);  
        switch(choice) {
            case 1:
                printf("Enter the item you want to push: ");
                scanf("%d", &item);
                push(&top, item);
                break;
            
            case 2:
                pop(&top);
                break;
            
            case 3:
                show(top);
                break;
            
            case 4:
                printf("Exiting...");
                break;
            
            default:
                printf("\nWrong choice entered\n");
        };   
    }
}
void push(stack **top, int item) {
    stack *ptr = (stack *)malloc(sizeof(stack));
    if(ptr == NULL) {
        printf("Overflow");
        return;
    }
    ptr -> info = item;
    if(*top == NULL){
        *top = ptr;
        ptr -> next = NULL;
    }
    else {
        ptr -> next = *top;
        *top = ptr;
    }
    printf("Item Pushed");
}

void pop(stack **top) {
    int item;
    stack *ptr;
    if(*top == NULL){
        printf("Underflow...");
        return;
    }
    item = (*top) -> info;
    ptr = *top;
    *top = (*top) -> next;
    free(ptr);
    printf("Item Popped: %d", item);
}

void show(stack *top){
    while(top){
        printf("%d\n", top -> info);
        top = top -> next;
    }
}
