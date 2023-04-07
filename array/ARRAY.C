#include<stdio.h>
#include<conio.h>
int linear_search(int [], int, int);
int binary_search(int [], int, int);
void traverse(int [], int);
void unsort_insert(int [], int, int, int);
void main(){
   int arr[100], n, item, i, res, choice;
   clrscr();
   printf("Enter the no. of elements:");
   scanf("%d", &n);
   printf("Enter %d elements of the array: ", n);
   for(i=0; i<n; i++){
     scanf("%d", &arr[i]);
   }
   printf("Enter the function you want to perform: \n1. Linear Search\n2. Binary Search\n3. Traverse ");
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

   case 2:
     printf("Enter the element you want to search for: ");
     scanf("%d", &item);
     res = binary_search(arr, n, item);
     if(res == -1)
       printf("Element not in the array");
     else
       printf("Element found at: %d position", res + 1);
  }
  getch();
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
int binary_search(int a[], int n, int item){
   int i, l, r, mid;
   l = 0;
   r = n - 1;
   while (l <= r){
     mid = (l + r) / 2;
     if(a[mid] < item)
	l = mid + 1;
     else if(a[mid] > item)
	r = mid - 1;
     else
	return mid;
   }
   return -1;
}
void traverse(int a[], int n){
  int i;
  for(i = 0; i < n; i++){
     printf("%d", a[i];
  }
}
void unsort_insert(int a[], int n, int loc, int item){
