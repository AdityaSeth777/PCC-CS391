#include <stdio.h>
#include <stdbool.h>

#define N 10

// Global Variables
int board[N][N];
bool row[N];
bool diag1[2*N - 1];
bool diag2[2*N - 1];
int count = 0;

// Function to check if a queen can be placed at a given position
bool isSafe(int row, int col) {
    return !row[row] && !diag1[row+col] && !diag2[row-col+N-1];
}

// Function to place a queen at a given position
void placeQueen(int row, int col) {
    board[row][col] = 1;
    row[row] = true;
    diag1[row+col] = true;
    diag2[row-col+N-1] = true;
}

// Function to remove a queen from a given position
void removeQueen(int row, int col) {
    board[row][col] = 0;
    row[row] = false;
    diag1[row+col] = false;
    diag2[row-col+N-1] = false;
}

// Function to print the board
void printBoard() {
    printf("Solution %d:\n", ++count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to solve the N-Queen problem using backtracking
void solve(int col) {
    if (col == N) {
        printBoard();
        return;
    }

    for (int row = 0; row < N; row++) {
        if (isSafe(row, col)) {
            placeQueen(row, col);
            solve(col+1);
            removeQueen(row, col);
        }
    }
}

int main() {
    // Get input for N
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Set N for the board
    N = n;

    // Solve the problem
    solve(0);

    return 0;
}
