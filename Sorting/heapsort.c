#include <stdio.h>
void heapSort(int [], int);
void heapify(int [], int);
void reheapifyDownward(int [], int , int);
int main() {
    int a[100], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    heapSort(a, n);
    printf("Sorted Array is: ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void heapSort(int a[], int n) {
    int temp;
    heapify(a, n);
    for (int i = n; i > 1; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        reheapifyDownward(a, 1, i - 1);
    }
}

void heapify(int a[], int n) {
    int index = n/2;
    for (int i = index; i >= 1; i--) 
        reheapifyDownward(a, i, n);
}

void reheapifyDownward(int a[], int start, int finish) {
    int maximum, index, temp, lchild, rchild;
    lchild = 2 * start;
    rchild= lchild - 1;
    if (lchild <= finish) {
        maximum = a[lchild];
        index = lchild;
    }
    if (rchild <= finish) {
        if (a[rchild] > maximum){
            maximum = a[rchild];
            index = rchild;
        }
    }
    if (a[start] < a[index]) {
        temp = a[start];
        a[start] = a[index];
        a[index] = temp;
        reheapifyDownward(a, index, finish);
    }
}
