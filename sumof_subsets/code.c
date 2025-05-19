#include <stdio.h>

int n, target;
int set[20], subset[20];

void sumOfSubsets(int index, int currSum, int subsetIndex) {
    if (currSum == target) {

        printf("{ ");
        for (int i = 0; i < subsetIndex; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    if (index == n || currSum > target) {
        return;
    }

    subset[subsetIndex] = set[index];
    sumOfSubsets(index + 1, currSum + set[index], subsetIndex + 1);

    sumOfSubsets(index + 1, currSum, subsetIndex);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements (positive integers):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets that sum to %d:\n", target);
    sumOfSubsets(0, 0, 0);

    return 0;
}
