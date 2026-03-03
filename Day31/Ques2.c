// Valid Parentheses

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

bool isValid(char s[]) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return false;

            char topChar = stack[top--];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[MAX];

    scanf("%s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}