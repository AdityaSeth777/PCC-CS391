This program solves the N-Bishop problem using backtracking in C.

The n variable is used to store the number of bishops to be placed on an n x n chessboard. The print_board() function is used to print the chessboard configuration.

The is_safe() function is used to check if it is safe to place a bishop at a given position on the board. It checks if there is any bishop on the diagonal from that position.

The solve() function uses backtracking to solve the problem. It takes the current board configuration, the current column number, and a pointer to the count of solutions found so far. If the current column number is equal to n, it means we have placed n bishops on the board and have found a solution, so we print the board and increment the solution count. If the current column number is less than n, we try to place a bishop in each row of the current column where it is safe to do so. We then recursively call the solve() function with the updated board and column number. If no solution is found for a given configuration, we backtrack by removing the bishop from the previous column.

In the main() function, we get input for n, initialize the board to all zeroes, and call the solve() function with the initial board configuration, column number zero, and a pointer to the solution count. Finally, we return 0 to indicate successful program execution.