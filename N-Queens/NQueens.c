#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10
void printBoard(int board[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1) {
            return false;
        }
        if (col + (row - i) < n && board[i][col + (row - i)] == 1) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int board[MAX_N][MAX_N], int row, int n, int* solutionCount) {
    if (row == n) {
        (*solutionCount)++;
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, n, solutionCount);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the board (n): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_N) {
        printf("Please enter a number between 1 and %d.\n", MAX_N);
        return 1;
    }

    int board[MAX_N][MAX_N] = {0};
    int solutionCount = 0;

    solveNQueens(board, 0, n, &solutionCount);

    if (solutionCount == 0) {
        printf("No solution exists.\n");
    } else {
        printf("Total solutions found: %d\n", solutionCount);
    }

    return 0;
}
