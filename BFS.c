#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

// BFS function
void bfs(int start) {
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
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

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}