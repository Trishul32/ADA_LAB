#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    // Fill DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    // Print compact DP table in 3-column format (only final row of each item)
    printf("\nCompact DP Table (selected weights):\n");
    printf("Item\tW=10\tW=20\tW=30\tW=40\tW=50\n");
    for (i = 0; i <= n; i++) {
        printf("%4s", (i == 0) ? "0" : ("i" + (char)(i + '0' - 1)));
        for (int cap = 10; cap <= 50; cap += 10) {
            printf("\t%3d", K[i][cap]);
        }
        printf("\n");
    }

    // Traceback to find selected items
    printf("\nSelected items:\n");
    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res != K[i-1][w]) {
            printf("Item %d: weight = %d, value = %d\n", i, wt[i-1], val[i-1]);
            res -= val[i-1];
            w -= wt[i-1];
        }
    }

    return K[n][W];
}

int main() {
    int val[] = {50, 90, 100};   // values
    int wt[] = {10, 20, 30};      // weights
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    int max_value = knapsack(W, wt, val, n);
    printf("\nMaximum value in Knapsack = %d\n", max_value);
    return 0;
}
