// Graph Cycle Detection

#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int parent, int visited[], struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neighbor = temp->vertex;   

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj))
                return true;
        }
        else if (neighbor != parent) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {
    struct Node* adj[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
        n1->vertex = v;   
        n1->next = adj[u];
        adj[u] = n1;

        struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
        n2->vertex = u;  
        n2->next = adj[v];
        adj[v] = n2;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj))
                return true;
        }
    }

    return false;
}