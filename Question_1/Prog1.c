#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char exp[]) {
    top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0;
            char open = pop();
            if (!isMatching(open, ch)) return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0';

    if (isBalanced(exp))
        printf("Expression has BALANCED parentheses\n");
    else
        printf("Expression has NOT BALANCED parentheses\n");

    return 0;
}
