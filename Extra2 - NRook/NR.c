#include <stdio.h>

int board[10][10], n;

// Function to check if a rook can be placed at a given position
int isSafe(int row, int col) {
    // Check if there is any rook in the same row
    for (int i = 0; i < n; i++) {
        if (board[row][i])
            return 0;
    }

    // Check if there is any rook in the same column
    for (int i = 0; i < n; i++) {
        if (board[i][col])
            return 0;
    }

    // Check if there is any rook in the diagonal
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

// Function to solve the N-Rook problem using backtracking
void solve(int col) {
    if (col == n) {
        // Print the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

int main() {
    // Get input for N
    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Initialize the board to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    // Solve the problem
    solve(0);

    return 0;
}
