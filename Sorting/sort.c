#include<stdio.h>
void bubbleSort(int [], int);
void display(int [], int);
void selectionSort(int [], int);
void main() {
    int arr[100], n, choice;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The input array is: ");
    display(arr, n);
    printf("\nEnter the sorting you want to perform:\n1. Bubble Sort\n2. Selection Sort\t");
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            bubbleSort(arr, n);
            display(arr, n);
            break;
        
        case 2:
            selectionSort(arr, n);
            display(arr, n);
            break;
    }
    
    
}

void display(int arr[], int n) {
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}
void swap(int *n1, int *n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void bubbleSort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int minIdx;
    for(int i = 0; i < n - 1; i++){
        minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if(minIdx != i)
            swap(&arr[i], &arr[minIdx]);
    }
}
