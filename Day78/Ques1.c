/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int to, weight;
} Edge;

Edge adj[MAX][MAX];
int adjSize[MAX];

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 1; v <= n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int n) {
    int key[n+1];
    bool mstSet[n+1];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;  
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].to;
            int w = adj[u][i].weight;

            if (!mstSet[v] && w < key[v]) {
                key[v] = w;
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adjSize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]++] = (Edge){v, w};
        adj[v][adjSize[v]++] = (Edge){u, w};
    }

    int result = primMST(n);
    printf("%d\n", result);

    return 0;
}