#include <stdio.h>
#include <math.h>

int main() {
    int low, high;

    printf("Enter the lower limit: ");
    scanf("%d", &low);
    printf("Enter the upper limit: ");
    scanf("%d", &high);

    printf("Armstrong numbers between %d and %d are:\n", low, high);

    for (int num = low; num <= high; num++) {
        int originalNum = num, remainder, n = 0;
        double result = 0.0;

        // Count digits
        while (originalNum != 0) {
            originalNum /= 10;
            ++n;
        }

        originalNum = num;

        // Calculate sum of digits^n
        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += pow(remainder, n);
            originalNum /= 10;
        }

        if ((int)result == num)
            printf("%d ", num);
    }

    printf("\n");
    return 0;
}
