#include <stdio.h>

#define SIZE 3       // Number of elements to permute
#define LEFT -1
#define RIGHT 1

// Check if a[i] is mobile (can move in its current direction)
int isMobile(int a[], int dir[], int i) {
    if (dir[i] == LEFT && i > 0 && a[i] > a[i - 1])
        return 1;
    if (dir[i] == RIGHT && i < SIZE - 1 && a[i] > a[i + 1])
        return 1;
    return 0;
}

// Get index of the largest mobile number
int getMobile(int a[], int dir[]) {
    int mobile = -1;
    for (int i = 0; i < SIZE; i++) {
        if (isMobile(a, dir, i)) {
            if (mobile == -1 || a[i] > a[mobile])
                mobile = i;
        }
    }
    return mobile;
}

// Swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Print current permutation
void printPermutation(int a[]) {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Main function to generate permutations using Johnson-Trotter
void johnsonTrotter() {
    int a[SIZE], dir[SIZE];

    // Step 1: Initialize elements and directions
    for (int i = 0; i < SIZE; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    // Step 2: Print the first permutation
    printPermutation(a);

    while (1) {
        int mobileIndex = getMobile(a, dir);
        if (mobileIndex == -1)
            break;

        int swapWith = mobileIndex + dir[mobileIndex];

        // Step 3: Swap values and their directions
        swap(&a[mobileIndex], &a[swapWith]);
        swap(&dir[mobileIndex], &dir[swapWith]);

        // Step 4: Reverse direction of all elements greater than the moved one
        for (int i = 0; i < SIZE; i++) {
            if (a[i] > a[swapWith])
                dir[i] = -dir[i];
        }

        // Step 5: Print the new permutation
        printPermutation(a);
    }
}

int main() {
    johnsonTrotter();
    return 0;
}
