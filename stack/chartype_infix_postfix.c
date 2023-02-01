#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR_LEN 100
#define MAX_STACK_LEN 100

char expr[MAX_EXPR_LEN];
char stack[MAX_STACK_LEN];
int top = -1;

int is_operand(char c) {
    return isalpha(c);
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

char peek() {
    return stack[top];
}

int is_empty() {
    return top == -1;
}

char *infix_to_postfix(char *infix) {
    int i, j;
    int infix_len = strlen(infix);
    char *postfix = malloc(infix_len + 1);

    for (i = 0, j = 0; i < infix_len; i++) {
        if (is_operand(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (!is_empty() && precedence(infix[i]) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (!is_empty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main() {
    printf("Enter an infix expression: ");
    scanf("%s", expr);
    char *postfix = infix_to_postfix(expr);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
    return 0;
}
