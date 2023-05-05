#include<stdio.h>
void bubbleSort(int [], int);
void display(int [], int);
void selectionSort(int [], int);
void main() {
    int arr[100], n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n)
    for(int i = 0; i < n; i++) {
        scanf("%d", arr[i]);
    }
    printf("The input array is: ");
    display(arr, n);
    switch(choice) {
        case 1: 
            bubbleSort(arr, n);
            display(arr, n);
    }
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    display(arr, n);
    
    
}

void display(int arr[], int n) {
    for(int i = 0; i < n ; i++){
        printf("%d", arr[i]);
    }
}

void bubbleSort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    
}
