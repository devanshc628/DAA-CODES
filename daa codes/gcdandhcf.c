#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int x = a, y = b; 
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD/HCF of %d and %d is: %d\n", x, y, a);

    return 0;
}
