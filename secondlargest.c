#include <stdio.h>
int secondLargest(int [], int);
int main() {
    int n, arr[50];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &arr[i]);
    }
    printf("Second Largest Number is: %d", secondLargest(arr, n));
    return 0;
}
int secondLargest(int a[], int n){
    int max_1 = 0, index = 0, max_2 = 0;
    for(int i = 0; i < n; i++){
        if (max_1 < a[i]){
            max_1 = a[i];
            index = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if (i == index)
            continue;
        else if(max_2 < a[i])
            max_2 = a[i];
    }
    return max_2;
}
