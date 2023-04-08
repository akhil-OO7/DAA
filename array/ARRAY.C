#include<stdio.h>
int linearSearch(int [], int, int);
int binarySearch(int [], int, int);
void traverse(int [], int);
void unsortedInsert(int [], int, int, int);
void sortedInsert(int [], int, int);
void bubbleSort(int [], int);
void main(){
   int arr[100], n, item, i, res, choice, key, pos;
   printf("Enter the no. of elements: ");
   scanf("%d", &n);
   printf("Enter %d elements of the array: ", n);
   for(i=0; i<n; i++){
     scanf("%d", &arr[i]);
   }
   printf("Enter the function you want to perform: \n1. Linear Search\n2. Binary Search\n3. Traverse\n4. Unsorted Insertion\n5. Sorted Insertion\n6. Deletion\n7. Sort ");
   scanf("%d", &choice);
   switch(choice){
    case 1:
         printf("Enter the element you want to search for: ");
         scanf("%d", &item);
         res = linearSearch(arr, n, item);
         if(res == -1)
           printf("Element not in the array");
         else
           printf("Element found at: %d position", res + 1);
         break;

    case 2:
         printf("Enter the element you want to search for: ");
         scanf("%d", &item);
         res = binarySearch(arr, n, item);
         if(res == -1)
           printf("Element not in the array");
         else
           printf("Element found at: %d position", res + 1);
         break;

    case 3:
         traverse(arr, n);
         break;

    case 4:
         printf("Enter the element and postion you want to insert: ");
         scanf("%d%d", &key, &pos);
         unsortedInsert(arr, n, pos, key);
         n++;
         traverse(arr,n);
         break;
    
    case 5:
         printf("Enter the element you want to insert: ");
         scanf("%d", &key);
         bubbleSort(arr,n);
         traverse(arr, n);
         sortedInsert(arr, n, key);
         n++;
         traverse(arr,n);
         break;
    
    case 6:
        printf("Enter the element you want to delete: ");
        scanf("%d", &key);
        pos = binarySearch(arr, n, key);
        if (pos == -1){
            printf("Element not found");
        }
        else{
            deletion(arr, n, pos, item);
            n--;
        }
        traverse(arr, n);
        break;
    
    case 7:
        bubbleSort(arr, n);
        traverse(arr,n);
        break;
    default:
        printf("Wrong Choice Entered");
        break;
  }
}
int linearSearch(int a[], int n, int item){
   int i;
   for(i=0; i<n; i++){
     if(a[i] == item){
       return i;
     }
   }
   return -1;
}
int binarySearch(int a[], int n, int item){
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
     printf("%d ", a[i]);
  }
}
void unsortedInsert(int a[], int n, int pos, int item){
    for(int i = n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = item;
}

void sortedInsert(int a[], int n, int item){
    int pos = 0;
    for(int i = 0; i < n; i++){
        if (item < a[i])
            pos++;
        else 
            break;
    }
    unsortedInsert(a, n, pos, item);
}

void deletion(int a[], int n, int pos, int item){
    for(int i = n - 1; i >= pos; i--){
        a[i] = a[i + 1];
    }
}
void bubbleSort(int a[], int n){
    int temp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
}
