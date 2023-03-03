#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int adj[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];

// Perform DFS traversal starting from the given vertex
void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);

    int i;
    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
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

    printf("DFS traversal: ");
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }
    printf("\n");

    return 0;
}
