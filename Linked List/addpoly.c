#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
    int power, coeff;
    struct nodeType *next;
}

node *poly1 = NULL;
node *poly2 = NULL;

void main(){
    while(1){
        createPoly(&poly1, c, p);
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
