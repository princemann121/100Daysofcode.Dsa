/* Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops) */

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void display() {
    if(top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {

    int n, m, x;

    scanf("%d", &n);

    // Push n elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}