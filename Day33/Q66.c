/* You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {

    int n;
    scanf("%d", &n);

    char token[20];

    for(int i = 0; i < n; i++) {

        scanf("%s", token);

        if(strcmp(token, "+") == 0 ||
           strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0) {

            int b = pop();
            int a = pop();

            if(strcmp(token, "+") == 0)
                push(a + b);
            else if(strcmp(token, "-") == 0)
                push(a - b);
            else if(strcmp(token, "*") == 0)
                push(a * b);
            else
                push(a / b);
        }
        else {
            push(atoi(token));
        }
    }

    printf("%d\n", pop());

    return 0;
}