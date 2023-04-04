#include <stdio.h>
int main() {
    int n, arr[50], num, flag = 0;
    printf("Enter no. of elements of the array: ");
    scanf("%d", &n);
    printf("Enter %d elements of the array: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the number you want to search for: ");
    scanf("%d", &num);
    for(int i = 0; i < n; i++){
        if (num == arr[i]) {
            flag = 1;
            printf("Number found at postion: %d", i + 1);
        }
    }
    if (flag == 0)
        printf("Number not found");
    return 0;
}
