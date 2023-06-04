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
    int max, index, temp, l, r;
    max = start;
    l = 2 * start;
    r = 2 * start + 1;
    if (l <= finish && a[l] > a[max])
        max = l;
    if (r <= finish && a[r] > a[max])
        max = r;
    if(start != max) {
        temp = a[start];
        a[start] = a[max];
        a[max] = temp;
        reheapifyDownward(a, max, finish);
    }
}
// #include<stdio.h>
// void heapSort(int [], int);
// void maxHeap(int [], int, int);
// void maxHeapify(int [], int, int);
// void main() {
//     int a[10], i;
//     for(i = 1; i < 10; i++){
//         scanf("%d", &a[i]);
//     }
//     maxHeap(a, 1, 9);
//     heapSort(a, 9);
//     for (i = 1; i < 10; i++) {
//         printf("%d ", a[i]);
//     }
// }

// void heapSort(int a[], int size) {
//     int i, t;
//     for(i = size; i >= 2; i--) {
//         t = a[1];
//         a[1] = a[i];
//         a[i] = t;
//         maxHeapify(a, 1, i - i);
//     }
// }

// void maxHeap(int a[], int beg, int end) {
//     int i;
//     for(i = end / 2; i >= beg; i--)
//     maxHeapify(a, i, end);
// }

// void maxHeapify(int a[], int f, int size) {
//     int max = f, l = f * 2, r = f * 2 + 1, t;
//     if (l <= size && a[l] > a[max])
//         max = l;
//     if (r <= size && a[r] > a[max])
//         max = r;
//     if (f != max) {
//         t = a[f];
//         a[f] = a[max];
//         a[max] = t;
//         maxHeapify(a, max, size);
//     }
// }
