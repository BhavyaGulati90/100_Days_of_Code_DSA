/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100000

int pq[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x) {
    int i = size;
    pq[size++] = x;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (pq[p] <= pq[i]) break;
        swap(&pq[p], &pq[i]);
        i = p;
    }
}

int deleteMin() {
    if (size == 0) return -1;

    int ans = pq[0];
    pq[0] = pq[size - 1];
    size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && pq[left] < pq[smallest]) smallest = left;
        if (right < size && pq[right] < pq[smallest]) smallest = right;

        if (smallest == i) break;

        swap(&pq[i], &pq[smallest]);
        i = smallest;
    }

    return ans;
}

int peek() {
    if (size == 0) return -1;
    return pq[0];
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    while (N--) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}