/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'*/

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, type, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &value);
            push(value);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            display();
        }
    }

    return 0;
}