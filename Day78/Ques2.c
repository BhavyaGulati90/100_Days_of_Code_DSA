// Articulation Points (GFG)

#include <stdbool.h>
#include <stdlib.h>

void dfs(int u, List** adj, bool visited[], int disc[], int low[],
         int parent[], bool ap[], int* time) {

    visited[u] = true;
    disc[u] = low[u] = (*time)++;
    int children = 0;

    List* temp = adj[u];

    while (temp != NULL) {
        int v = temp->val;

        // Ignore self-loop
        if (v == u) {
            temp = temp->next;
            continue;
        }

        if (!visited[v]) {
            children++;
            parent[v] = u;

            dfs(v, adj, visited, disc, low, parent, ap, time);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Root node case
            if (parent[u] == -1 && children > 1)
                ap[u] = true;

            // Non-root case
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;

        } else if (v != parent[u]) {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }
}

int* articulationPoints(int V, List** adj, int* returnSize) {

    bool* visited = (bool*)calloc(V, sizeof(bool));
    int* disc = (int*)malloc(V * sizeof(int));
    int* low = (int*)malloc(V * sizeof(int));
    int* parent = (int*)malloc(V * sizeof(int));
    bool* ap = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    int time = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, disc, low, parent, ap, &time);
        }
    }

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) count++;
    }

    // If no articulation point
    if (count == 0) {
        int* res = (int*)malloc(sizeof(int));
        res[0] = -1;
        *returnSize = 1;
        return res;
    }

    int* result = (int*)malloc(count * sizeof(int));
    int idx = 0;

    // Already sorted because we traverse 0 → V-1
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            result[idx++] = i;
        }
    }

    *returnSize = count;
    return result;
}