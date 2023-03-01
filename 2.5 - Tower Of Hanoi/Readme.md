This program implements the Tower of Hanoi problem recursively in C language, with an added step counter to count the total number of steps taken to solve the problem.

The tower_of_hanoi() function takes four arguments: the number of disks n, and the three rods from_rod, to_rod, and aux_rod. It recursively solves the problem by moving n-1 disks from the from_rod to the aux_rod, then moving the remaining disk from the from_rod to the to_rod, and finally moving the n-1 disks from the aux_rod to the to_rod. Each move is printed with a step number that is incremented each time a disk is moved.

In the main() function, the user is prompted to enter the number of disks to be moved. The tower_of_hanoi() function is called with the initial configuration of the rods. After the function completes, the total number of steps taken is printed out.

Overall, this program is a simple and elegant implementation of the Tower of Hanoi problem in C language, with the added benefit of a step counter to help analyze the performance of the algorithm.