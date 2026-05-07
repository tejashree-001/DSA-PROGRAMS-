#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function
void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}