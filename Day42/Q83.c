/* Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers */

#include <stdio.h>

#define MAX 100

int main() {

    int queue[MAX], stack[MAX];
    int front = 0, rear = -1;
    int top = -1;
    int n;

    scanf("%d", &n);

    // Input queue elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    // Push queue elements to stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Pop stack to queue
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    // Print reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}