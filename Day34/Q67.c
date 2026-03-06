/* Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push
void push(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {

    char postfix[100];
    scanf("%s", postfix);

    for(int i = 0; postfix[i] != '\0'; i++) {

        char c = postfix[i];

        // Operand
        if(isdigit(c)) {
            push(c - '0');
        }
        // Operator
        else {
            int b = pop();
            int a = pop();

            int result;

            switch(c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
    }

    printf("%d\n", pop());

    return 0;
}