/* Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters) */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

// Initialize stack
void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

// Push element
void push(MinStack *s, int val) {
    s->stack[++s->top] = val;

    if (s->minTop == -1 || val <= s->minStack[s->minTop]) {
        s->minStack[++s->minTop] = val;
    }
}

// Pop element
void pop(MinStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    if (s->stack[s->top] == s->minStack[s->minTop]) {
        s->minTop--;
    }

    s->top--;
}

// Get top element
int top(MinStack *s) {
    if (s->top == -1) return -1;
    return s->stack[s->top];
}

// Get minimum element
int getMin(MinStack *s) {
    if (s->minTop == -1) return -1;
    return s->minStack[s->minTop];
}

int main() {
    MinStack s;
    init(&s);

    int n;
    scanf("%d", &n);

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);
            push(&s, x);
        }
        else if (op == 2) {
            pop(&s);
        }
        else if (op == 3) {
            printf("%d\n", top(&s));
        }
        else if (op == 4) {
            printf("%d\n", getMin(&s));
        }
    }

    return 0;
}