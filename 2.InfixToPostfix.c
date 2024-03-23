#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}
char pop() {
    return stack[top--];
}
int precedence(char c) {
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 3;  
}
int main() {
    char infix[50], postfix[50], c, x;
    int i = 0, j = 0;
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("The Postfix expression is : %s\n", postfix);

    return 0;
}
