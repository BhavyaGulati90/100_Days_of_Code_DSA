// Redundant Connection

#include <stdlib.h>

int findParent(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]); 
    return parent[x];
}

void unionSet(int parent[], int x, int y) {
    int px = findParent(parent, x);
    int py = findParent(parent, y);
    if (px != py)
        parent[px] = py;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
    int *parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }
    
    int *result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);
        
        if (pu == pv) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(parent, u, v);
        }
    }
    
    *returnSize = 2;
    return result;
}