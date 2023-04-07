#include<stdio.h>
#include<conio.h>
int linear_search(int [], int, int);
int binary_search(int [], int, int);
void main(){
   int arr[100], n, item, i, res, choice;
   clrscr();
   printf("Enter the no. of elements:");
   scanf("%d", &n);
   printf("Enter %d elements of the array: ", n);
   for(i=0; i<n; i++){
     scanf("%d", &arr[i]);
   }
   printf("Enter the function you want to perform: \n1.Linear Search ");
   scanf("%d", &choice);
   switch(choice){
   case 1:
     printf("Enter the element you want to search for: ");
     scanf("%d", &item);
     res = linear_search(arr, n, item);
     if(res == -1)
       printf("Element not in the array");
     else
       printf("Element found at: %d position", res + 1);
   getch();
  }
}
int linear_search(int a[], int n, int item){
   int i;
   for(i=0; i<n; i++){
     if(a[i] == item){
       return i;
     }
   }
   return -1;
}