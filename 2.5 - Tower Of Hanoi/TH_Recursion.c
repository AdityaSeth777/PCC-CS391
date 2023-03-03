#include <stdio.h>

int step_count = 0;

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Step %d: Move disk 1 from rod %c to rod %c\n", ++step_count, from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Step %d: Move disk %d from rod %c to rod %c\n", ++step_count, n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    printf("Total number of steps: %d\n", step_count);
    return 0;
}
//Aditya Seth - setha4195@gmail.com