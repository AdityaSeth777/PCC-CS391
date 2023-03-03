Question -> N-Queen in C using backtracking



The given code implements the N-Queen problem in C using backtracking.

First, global variables are defined to store the board state, row, diagonal 1, and diagonal 2 information. The size of the board is set to 10, but the user is prompted to input the desired value of N.

The isSafe function checks if a queen can be placed at a given position by checking if there is no queen present in the same row, same diagonal 1, and same diagonal 2.

The placeQueen function places a queen at a given position by setting the respective entries in the board and row, diagonal 1, and diagonal 2 arrays to true.

The removeQueen function removes a queen from a given position by setting the respective entries in the board and row, diagonal 1, and diagonal 2 arrays to false.

The printBoard function prints the current board state to the console.

The solve function recursively solves the N-Queen problem using backtracking. It starts with the first column (col = 0) and checks if a queen can be placed in each row of that column. If a queen can be placed, it is placed, and the function is called recursively with col+1 as the argument. If a solution is found (col == N), the board is printed. If a queen cannot be placed, the function backtracks by removing the previously placed queen and trying the next row.

Finally, in the main function, the user is prompted to input the value of N. Then, the solve function is called with col = 0 to solve the N-Queen problem.