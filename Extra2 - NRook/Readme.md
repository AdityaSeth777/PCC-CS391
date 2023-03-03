Question -> N-Rook in C using backtracking


This is a C program that solves the N-Rook problem using backtracking. The program takes the value of N as input from the user and prints all the possible solutions where N rooks can be placed on an NxN chessboard such that no two rooks attack each other.

The program uses a two-dimensional array board to represent the chessboard and a function isSafe() to check if a rook can be placed at a given position without attacking any other rook. The function checks if there is any rook in the same row, column, or diagonal as the given position. If there is no rook in any of these positions, the function returns 1, indicating that the position is safe.

The solve() function is the main recursive function that solves the N-Rook problem using backtracking. It takes the column number as input and tries to place a rook in each row of the given column. If a rook can be placed at a given position, the function marks the position on the chessboard as occupied and recursively calls itself with the next column number. If the function is able to place N rooks on the chessboard without any of them attacking each other, it prints the solution by printing the board array.

The main() function takes the value of N as input from the user, initializes the board array to 0, and calls the solve() function with column number 0 to start the backtracking algorithm.

The time complexity of the program is O(N!), which is the number of possible solutions to the N-Rook problem. However, the actual running time of the program will depend on the input value of N and the performance of the computer running the program.