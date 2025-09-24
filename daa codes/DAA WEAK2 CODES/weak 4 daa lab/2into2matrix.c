#include <stdio.h>

int main() {
    // Declare the matrices and the result matrix
    int matrix1[10][10];
    int matrix2[10][10];
    int result[10][10];

    int rows1, cols1, rows2, cols2;
    int i, j, k;

    // --- Inputting Matrix 1 ---
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // --- Inputting Matrix 2 ---
    printf("\n");
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Error: Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second.\n");
        return 1; // Exit with an error code
    }

    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // --- Printing the Input Matrices ---
    printf("\nMatrix 1:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    // --- Performing Matrix Multiplication ---
    // The core of the multiplication algorithm
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            // Initialize the element to 0 before calculating the sum of products
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                // The element at result[i][j] is the sum of the products of
                // the elements in the i-th row of matrix1 and the j-th column of matrix2.
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // --- Printing the Result Matrix ---
    printf("\nThe resulting matrix is:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n"); // New line for each row
    }

    return 0; // Exit successfully
}
