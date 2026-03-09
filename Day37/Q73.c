/* Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations */

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if(size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    int minIndex = 0;

    for(int i = 1; i < size; i++) {
        if(pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete highest priority (smallest value)
void deletePQ() {

    if(size == 0) {
        printf("Queue Empty\n");
        return;
    }

    int minIndex = findMinIndex();
    int deleted = pq[minIndex];

    for(int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;

    printf("%d\n", deleted);
}

// Peek highest priority
void peek() {

    if(size == 0) {
        printf("Queue Empty\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        char op[10];
        scanf("%s", op);

        if(op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd') {
            deletePQ();
        }
        else if(op[0] == 'p') {
            peek();
        }
    }

    return 0;
}