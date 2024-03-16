#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;  // Assuming '(' and ')' have the lowest precedence
}

// Function to convert infix expression to postfix expression
char* infix_to_postfix(char* infix_expr) {
    int len = strlen(infix_expr);
    char* postfix_expr = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;
    char stack[len];
    for (int i = 0; i < len; i++) {
        char c = infix_expr[i];
        if (isalnum(c)) {
            postfix_expr[++top] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix_expr[++top] = stack[top--];
            }
            top--;  // Pop '('
        } else {  // Operator encountered
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix_expr[++top] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) {
        postfix_expr[++top] = stack[top--];
    }
    postfix_expr[++top] = '\0';
    return postfix_expr;
}

// Example usage
int main() {
    printf("Hello world");
    char infix_expression[] = "A + B * C";
    char* postfix_expression = infix_to_postfix(infix_expression);
    printf("Postfix expression: %s\n", postfix_expression);
    free(postfix_expression);
    return 0;
}
