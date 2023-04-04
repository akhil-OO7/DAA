#include <stdio.h>
int fib(int);
int main() {
    int n;
    printf("Enter n to generate fibonacci series (upto n): ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        printf("%d ", fib(i));
    
    return 0;
}
int fib(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
