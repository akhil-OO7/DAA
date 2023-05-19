#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType {
    int info;
    struct nodeType *left;
    struct nodeType *right;
}bst;

bst *root = NULL;

void insert(bst **, int);
void preorder(bst *);
void inorder(bst *);
void postorder(bst *);

int main() {
    int choice, item;
    while(1) {
        printf("Enter the operation you want to perform: \n1. Insertion\n2. Preorder Traversal\n3. Inorder Traversal\n4. Post order Traversal\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &item);
                insert(&root, item);
                break;
            
            case 2:
                preorder(root);
                break;
                
            case 3:
                inorder(root);
                break;
                
            case 4:
                postorder(root);
                break;
                
            default:
                exit(0);
        }
    }

    return 0;
}

void insert(bst **root, int item) {
    bst *loc, *parent;
    bst *ptr = (bst*)malloc(sizeof(bst));
    ptr -> info = item;
    ptr -> left = ptr -> right = NULL;
    if (*root == NULL)
        *root = ptr;
    else {
        loc = *root;
        while(loc != NULL){
        parent = loc;
        if (item < loc -> info)
            loc = loc -> left;
        else
            loc = loc -> right;
        }
        if (item > parent -> info)
            parent -> right = ptr;
        else
            parent -> left = ptr;
    }
}
    
    // else if (item > (*root) -> info)
    //     insert(root -> right, item);
    // else
    //     insert(root -> left, item);

void preorder(bst *root) {
    if (root != NULL){
        printf("%d ", root -> info);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(bst *root) {
    if (root != NULL){
        inorder(root -> left);
        printf("%d ", root -> info);
        inorder(root -> right);
    }
}

void postorder(bst *root) {
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d", root -> info);
    }
}
