/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED */

#include <stdio.h>
#include <stdlib.h>

int visited[100005];
int *adj[100005];
int size[100005];

void dfs(int node) {
    visited[node] = 1;
    
    for(int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(100 * sizeof(int));
        size[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u; 
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}