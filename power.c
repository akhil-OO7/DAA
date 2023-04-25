#include <stdio.h>
int power(int, int);
void main() {
    int num, p, result;
    printf("Enter the number and it's exponent to calculate: ");
    scanf("%d%d", &num, &p);
    result = power(num, p);
    printf("%d^%d: %d", num, p, result);
}
int power(int n, int e){
    if(e != 0)
        return (n * power(n, e - 1));
    else
        return 1;
}
