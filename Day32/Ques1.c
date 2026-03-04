/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}

void pop() {
    if (top == -1)
        return;
    top--;
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        pop();
    }

    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}