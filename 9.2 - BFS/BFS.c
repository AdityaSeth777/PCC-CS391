#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int adj[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

// Add a vertex to the queue
void enqueue(int v) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = v;
    }
}

// Remove a vertex from the queue
int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue underflow.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}
//Aditya Seth - setha4195@gmail.com
// Perform BFS traversal starting from the given vertex
void bfs(int v, int n) {
    visited[v] = 1;
    enqueue(v);

    while (front != -1) {
        v = dequeue();
        printf("%d ", v);

        int i;
        for (i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int i, j;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("BFS traversal: ");
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, n);
        }
    }
    printf("\n");

    return 0;
}
