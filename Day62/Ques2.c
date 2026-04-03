// Keys and Rooms

#include <stdio.h>
#include <stdbool.h>

void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    dfs(0, rooms, roomsColSize, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }

    return true;
}