#include <stdio.h>

int main() {
    int n, k, i, j;
    
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of rotations (k): ");
    scanf("%d", &k);



    for(i = 0; i < k; i++) {
        int last = arr[n-1];   
        for(j = n-1; j > 0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = last;
    }

    printf("Array after %d right rotations: ", k);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
