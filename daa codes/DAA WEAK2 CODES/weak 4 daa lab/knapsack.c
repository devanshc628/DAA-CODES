#include <stdio.h>
#include <stdlib.h> // For max function (or you can write your own)

// A utility function to return max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
// W: maximum capacity of the knapsack
// wt[]: array of weights of the items
// val[]: array of values (profits) of the items
// n: number of items
int knapSack(int W, int wt[], int val[], int n) {
    // dp table to store the maximum value for each subproblem
    // dp[i][w] will store the max value with i items and capacity w
    int dp[n + 1][W + 1];

    // Build the dp table from the bottom up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base case: If no items or no capacity, the value is 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If the current item's weight is less than or equal to the current capacity
            else if (wt[i - 1] <= w) {
                // We have two choices:
                // 1. Include the item: val[i-1] + the max value of the remaining capacity (w - wt[i-1]) with the previous items (i-1)
                // 2. Exclude the item: the max value with the previous items (i-1) and the same capacity (w)
                // We take the maximum of these two choices.
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            // If the current item's weight is greater than the current capacity, we cannot include it
            else {
                // We just carry forward the value from the previous item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is in the bottom-right corner of the dp table
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("The maximum value that can be put in the knapsack is: %d\n", knapSack(W, wt, val, n));

    return 0;
}