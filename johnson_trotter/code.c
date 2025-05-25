#include <stdio.h>
#define SIZE 3

#define LEFT -1
#define RIGHT 1

int isMobile(int a[], int dir[], int i)
{
    if (dir[i] == LEFT && i != 0 && a[i] > a[i - 1])
        return 1;
    if (dir[i] == RIGHT && i != SIZE - 1 && a[i] > a[i + 1])
        return 1;
    return 0;
}

int getMobile(int a[], int dir[])
{
    int mobile = 0;
    for (int i = 0; i < SIZE; i++)
        if (isMobile(a, dir, i))
            if (a[i] > a[mobile] || !isMobile(a, dir, mobile))
                mobile = i;
    return isMobile(a, dir, mobile) ? mobile : -1;
}

// Swap elements and their directions
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printPermutation(int a[])
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter()
{
    int a[SIZE], dir[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a);

    while (1)
    {
        int mobileIndex = getMobile(a, dir);
        if (mobileIndex == -1)
            break;

        int swapWith = mobileIndex + dir[mobileIndex];
        swap(&a[mobileIndex], &a[swapWith]);
        swap(&dir[mobileIndex], &dir[swapWith]);

        for (int i = 0; i < SIZE; i++)
            if (a[i] > a[swapWith])
                dir[i] = -dir[i];

        printPermutation(a);
    }
}

int main()
{
    johnsonTrotter();
    return 0;
}
