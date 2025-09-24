#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers (from 0 to %d, one missing):\n", n, n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int total = (n * (n + 1)) / 2;   // expected sum of numbers from 0..n
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Missing number is: %d\n", total - sum);

    return 0;
}
