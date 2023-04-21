#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
    int power, coeff;
    struct nodeType *next;
}node;

node *poly1 = NULL;
node *poly2 = NULL;
node *poly3 = NULL;

void createPoly(node **, int, int);
void addPoly(node *, node *, node **);
void traverse(node *);
void multiplyPoly(node *, node *, node **);
node *linearSearch(node *, int);

void main() {
    int choice, c, p;
    while(1) {
        printf("\nEnter your choice:\n1. Create 1st Polynomial\n2. Create 2nd Polynomial\n3. Traverse\n4. Add\n5. Multiply\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter coefficient and power of x of Polynomial 1: ");
                scanf("%d%d", &c, &p);
                createPoly(&poly1, c, p);
                break;
            
            case 2:
                printf("Enter coefficient and power of x of Polynomial 2: ");
                scanf("%d%d", &c, &p);
                createPoly(&poly2, c, p);
                break;
                
            case 3:
                int ch;
                printf("Enter the Polynomial you want to display (1, 2, 3): ");
                scanf("%d", &ch);
                switch(ch){
                    case 1:
                        traverse(poly1);
                        break;
                    
                    case 2:
                        traverse(poly2);
                        break;
                        
                    case 3:
                        traverse(poly3);
                        break;
                        
                    default:
                        printf("Wrong Choice Entered");
                        break;
                }
            case 4:
                addPoly(poly1, poly2, &poly3);
                break;
            
            case 5:
                multiplyPoly(poly1, poly2, &poly2);
                break;
                
            default:
                exit(0);
        }
        
    }
}

void createPoly(node **poly, int c, int p){
    node *ptr = (node*)malloc(sizeof(node));
    ptr -> coeff = c;
    ptr -> power = p;
    if(*poly == NULL){
        ptr -> next = NULL;
    } else {
        ptr -> next = *poly;
    }
    *poly = ptr;
}

void addPoly(node *poly1, node *poly2, node **poly3){
    int c, p;
    while(poly1 != NULL && poly2 != NULL){
        if(poly1 -> power > poly2 -> power){
            c = poly1 -> coeff;
            p = poly1 -> power;
            createPoly(poly3, c, p);
            poly1 = poly1 -> next;
        } else if(poly1 -> power < poly2 -> power){
            c = poly2 -> coeff;
            p = poly2 -> power;
            createPoly(poly3, c, p);
            poly2 = poly2 -> next;
        } else {
            c = poly1 -> coeff + poly2 -> coeff;
            if( c != 0){
                p = poly1 -> power;
                createPoly(poly3, c, p);
            }
        }
        poly1 = poly1 -> next;
        poly2 = poly2 -> next;
    }
}

void traverse(node *tmp) {
    if(tmp == NULL){
        printf("NULL");
        return;
    }
    while(tmp){
        if(tmp -> next != NULL)
            printf("%dx^%d + ", tmp -> coeff, tmp -> power);
        else if(tmp -> power == 0)
            printf("%d", tmp -> coeff);
        else
            printf("%dx^%d", tmp -> coeff, tmp -> power);
        tmp = tmp -> next;
    }
}

void multiplyPoly(node *poly1, node *poly2, node **poly3) {
    int c, p;
    node *ptr1, *ptr2, *loc;
    ptr1 = poly1;
    ptr2 = poly2;
    while(ptr1) {
        ptr2 = poly2;
        while(ptr2) {
            c = ptr1 -> coeff * ptr2 -> coeff;
            p = ptr1 -> power + ptr2 -> power;
            loc = linearSearch(*poly3, p);
            if(loc == NULL)
                createPoly(poly3, c, p);
            else
                loc -> coeff = loc -> coeff + c;
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
}

node *linearSearch(node *poly3, int p){
    while(poly3){
        if(poly3 -> power == p)
            return poly3;
        poly3 = poly3 -> next;
    }
    return NULL;
}
