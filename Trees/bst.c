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
void search(bst **, bst **, int);
void deletion(bst **root, int);
bst *inorderSuccesor(bst *root);

int main() {
    int choice, item;
    while(1) {
        printf("Enter the operation you want to perform: \n1. Insertion\n2. Insertion Recursively\n3. Preorder Traversal\n4. Inorder Traversal\n5. Post order Traversal\n6. Deletion \t");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &item);
                insert(&root, item);
                break;
            
            // case 2:
            //     printf("Enter the value you want to insert: ");
            //     scanf("%d", &item);
            //     insertRec(&root, item);
            //     break;
            
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
                
            case 6:
                printf("Enter the number you want to delete: ");
                scanf("%d", &item);
                deletion(&root, item);
                break;
                
            default:
                exit(0);
        }
    }

    return 0;
}

// bst create(int item) {
//     bst *ptr = (bst *)malloc(sizeof(bst));
//     ptr -> info = item;
//     ptr -> left = ptr -> right = NULL;
//     return ptr;
    
// }

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

// void insertRec(bst **root, int item) {
//     bst *ptr = (bst *)malloc(sizeof(bst));
//     ptr -> info = item;
//     ptr -> left = ptr -> right = NULL;
//     if (*root == NULL)
//         *root = ptr;
//     else if(ptr -> info < (*root) -> info)
//         insertRec((*root) -> left, item);
//     else
//         insertRec((*root) -> right, item);
// }

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
        printf("%d ", root -> info);
    }
}

bst *inorderSuccesor(bst *curr) {
    while(curr -> left != NULL)
        curr = curr -> left;
    return curr;
}

void search(bst **curr, bst **parent, int item){
    while(*curr != NULL && (*curr) -> info != item){
        *parent = *curr;
        if(item < (*curr) -> info)
            (*curr) = (*curr) -> left;
        else
            (*curr) = (*curr) -> right;
    }
}
void deletion(bst **root, int item){
    bst *parent = NULL;
    bst *curr = *root;
    search(&curr, &parent, item);
    
    if(curr == NULL){
        printf("Item not in the Tree");
        return;
    }
    
    if (curr -> left == NULL && curr -> right == NULL) {
        if(curr != *root) {
            if(parent -> left == curr)
                parent -> left = NULL;
            else
                parent -> right = NULL;
        }
        else
            *root = NULL;
        free(curr);
    }
    else if(curr -> left && curr -> right) {
        bst *succ = inorderSuccesor(curr -> right);
        int val = succ -> info;
        deletion(root, val);
        curr -> info = val;
    }
    else {
        bst *child = curr -> left? curr -> left: curr -> right;
        if(curr != *root){
            if(parent -> left == curr)
                parent -> left = child;
            else
                parent -> right = child;
        }
        else
            free(curr);
    }
}
