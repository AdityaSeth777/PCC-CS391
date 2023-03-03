#include <stdio.h>
#include <stdlib.h>

int n;

void print_board(int board[n][n]) {
    // Print the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_safe(int board[n][n], int row, int col) {
    // Check if there is any bishop in the diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    for (int i = row, j = col; i < n && j < n; i++, j++) {
        if (board[i][j])
            return 0;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return 0;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

void solve(int board[n][n], int col, int *count) {
    if (col == n) {
        // Print the board
        printf("Solution %d:\n", ++(*count));
        print_board(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;
            solve(board, col + 1, count);
            board[i][col] = 0;
        }
    }
}
//Aditya Seth - setha4195@gmail.com
int main() {
    // Get input for N
    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Initialize the board to 0
    int board[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    // Solve the problem
    int count = 0;
    solve(board, 0, &count);

    return 0;
}
