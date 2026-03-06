// Basic Calculator II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(char *s) {
    int n = strlen(s);
    int num = 0;
    char op = '+';
    int stack[100000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
            if (op == '+') {
                stack[++top] = num;
            } else if (op == '-') {
                stack[++top] = -num;
            } else if (op == '*') {
                stack[top] = stack[top] * num;
            } else if (op == '/') {
                stack[top] = stack[top] / num;
            }

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}