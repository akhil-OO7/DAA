#include<stdio.h>
#include<conio.h>
int linear_search(int [], int, int);
int binary_search(int [], int, int);
void traverse(int [], int);
void unsort_insert(int [], int, int, int, int);
void main(){
   int arr[100], n, item, i, res, choice, key, pos;
   clrscr();
   printf("Enter the no. of elements:");
   scanf("%d", &n);
   printf("Enter %d elements of the array: ", n);
   for(i=0; i<n; i++){
     scanf("%d", &arr[i]);
   }
   printf("Enter the function you want to perform: \n1. Linear Search\n2. Binary Search\n3. Traverse4. Unsorted Insertion ");
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

   case 3:
     traverse(arr, n);

   case 4:
     printf("Enter the element and postion you want to insert: ");
     scanf("%d%d", &key, &pos);
     unsort_insert(arr, n, pos, key);
     n++;
     traverse(arr,n);
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
  printf("The array is:\n");
  for(i = 0; i < n; i++){
     printf("%d ", a[i];
  }
}
void unsort_insert(int a[], int n, int pos, int item){
    for(i = n - 1; i >= pos; i--){
       arr[i + 1] = arr[i];
    arr[pos] = item;
}