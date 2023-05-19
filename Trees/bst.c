#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType {
    int info;
    struct nodeType *left;
    struct nodeType *right;
}bst;

bst *root = NULL;
bst create(int);
void insert(bst **, int);
void preorder(bst *);
void inorder(bst *);
void postorder(bst *);
void insertRec(bst **, int);

int main() {
    int choice, item;
    while(1) {
        printf("Enter the operation you want to perform: \n1. Insertion\n2. Insertion Recursively\n3. Preorder Traversal\n4. Inorder Traversal\n5. Post order Traversal\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &item);
                insert(&root, item);
                break;
            
            case 2:
                printf("Enter the value you want to insert: ");
                scanf("%d", &item);
                insertRec(&root, item);
                break;
            
            case 3:
                preorder(root);
                printf("\n");
                break;
                
            case 4:
                inorder(root);
                printf("\n");
                break;
                
            case 5:
                postorder(root);
                printf("\n");
                break;
                
            default:
                exit(0);
        }
    }

    return 0;
}

bst create(int item) {
    bst *ptr = (bst *)malloc(sizeof(bst));
    ptr -> info = item;
    ptr -> left = ptr -> right = NULL;
    return ptr;
    
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

void insertRec(bst **root, int item) {
    bst *ptr = (bst *)malloc(sizeof(bst));
    ptr -> info = item;
    ptr -> left = ptr -> right = NULL;
    if (*root == NULL)
        *root = ptr;
    else if(ptr -> info < (*root) -> info)
        insertRec((*root) -> left, item);
    else
        insertRec((*root) -> right, item);
}

void preorder(bst *root) {
    if (root != NULL){
        printf("%d ", root -> info);
        preorder(root -> left);
        preorder(root -> right);
    }
    else
        printf("Empty");
}

void inorder(bst *root) {
    if (root != NULL){
        inorder(root -> left);
        printf("%d ", root -> info);
        inorder(root -> right);
    }
    else
        printf("Empty");
}

void postorder(bst *root) {
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> info);
    }
    else
        printf("Empty");
}
