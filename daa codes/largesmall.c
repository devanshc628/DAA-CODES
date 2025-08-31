#include <stdio.h>

int main() {
    int arr[5] = {64, 34, 25, 12, 22}; // Fixed size 
    int n = 5; 
    int largest, smallest;
    
    
    largest = arr[0];
    smallest = arr[0];

    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; 
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}
