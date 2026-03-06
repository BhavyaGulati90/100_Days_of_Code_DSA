/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        return 0;
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int evaluatePostfix(char* expr) {
    Node* top = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&top, atoi(token));
        } else if (isOperator(token[0])) {
            int b = pop(&top);
            int a = pop(&top);
            int result = 0;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&top, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&top);
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    printf("%d\n", evaluatePostfix(expr));

    return 0;
}