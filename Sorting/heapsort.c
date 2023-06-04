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
// void maxHeap(int [], int);
// void heapify(int [], int, int);

// void main() {
//     int arr[100], n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter %d elements of array: ", n);
//     for(int i = 1; i <= n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     heapSort(arr, n);
//     printf("Sorted Array is: ");
//     for(int i = 1; i <= n; i++) {
//         printf("%d ", arr[i]);
//     }
// }

// void heapSort(int a[], int size) {
//     maxHeap(a, size);
//     for(int i = size; i >= 2; i--) {
//         int temp = a[1];
//         a[1] = a[i];
//         a[i] = temp;
//         heapify(a, 1, i - 1);
//     }
// }

// void maxHeap(int a[], int size) {
//     for (int i = size / 2; i >= 1; i--)
//         heapify(a, i, size);
// }

// void heapify(int a[], int f, int size) {
//     int max = f, l = f * 2, r = f * 2 + 1, t;
//     if (l <= size && a[l] > a[max])
//         max = l;
//     if (r <= size && a[r] > a[max])
//         max = r;
//     if (f != max) {
//         t = a[f];
//         a[f] = a[max];
//         a[max] = t;
//         heapify(a, max, size);
//     }
// }
