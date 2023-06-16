#include<stdio.h>
void quicksort(int [], int, int);
int partition(int [], int, int);
void display(int [], int);
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
    printf("\nEnter the sorting you want to perform:\n1. Quick Sort\n2. Merge Sort\t");
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            quicksort(arr, 0, n-1);
            display(arr, n);
            break;
        
        case 2:
        //     selectionSort(arr, n);
        //     display(arr, n);
            break;
    };
}
void quicksort(int a[], int start, int end) 
{  
    if (start < end)  
    {  
        int p = partition(a, start, end);
        quicksort(a, start, p - 1);  
        quicksort(a, p + 1, end);  
    }  
}
int partition(int a[], int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j++) {
        if(a[j] < pivot){  
            i++;
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}

void display(int arr[], int n) {
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}
