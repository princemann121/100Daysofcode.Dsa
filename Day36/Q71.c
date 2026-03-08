/* Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations) */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;

    if(front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

// Dequeue
void dequeue() {

    if(front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    struct node* temp = front;

    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display
void display() {

    if(front == NULL)
        return;

    struct node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
}

int main() {

    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}