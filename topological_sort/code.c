#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];  // Adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// DFS function
void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    push(v);  // Push to stack after visiting all neighbors
}

// Topological sort
void topologicalSort(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, n);
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

// Main function
int main() {
    int n = 6;  // Number of vertices

    // Initialize graph with 0s
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // Add directed edges
    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    topologicalSort(n);

    return 0;
}
