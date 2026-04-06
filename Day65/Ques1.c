/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO */

#include <stdio.h>
#include <stdlib.h>

int adj[100][100], visited[100];

int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}