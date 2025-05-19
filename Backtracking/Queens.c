#include <stdio.h>
#include <stdbool.h>

#define N 4

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveNQueens(int board[N][N], int row, int *count) {
    if (row >= N) {
        (*count)++;
        printBoard(board);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, count);
            board[row][col] = 0;
        }
    }
}

int main() {
    int board[N][N] = {0};
    int count = 0;

    solveNQueens(board, 0, &count);

    printf("Total number of solutions for N = %d: %d\n", N, count);

    return 0;
}
