// Critical Connections in a Network

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timeCounter;

void dfs(int u, int parent, int* disc, int* low,
         int** adj, int* adjSize,
         int** result, int* returnSize) {

    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize);

            if (low[v] < low[u]) low[u] = low[v];

            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {

    int* degree = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        degree[connections[i][0]]++;
        degree[connections[i][1]]++;
    }

    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = 0;
    timeCounter = 0;

    dfs(0, -1, disc, low, adj, adjSize, result, returnSize);

    return result;
}