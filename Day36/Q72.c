/* Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

Deque* createDeque(int k){
    Deque* d = malloc(sizeof(Deque));
    d->arr = malloc(sizeof(int)*k);
    d->capacity = k;
    d->size = 0;
    d->front = 0;
    d->rear = -1;
    return d;
}

int insertFront(Deque* d, int val){
    if(d->size == d->capacity) return 0;

    d->front = (d->front - 1 + d->capacity) % d->capacity;
    d->arr[d->front] = val;
    d->size++;

    if(d->size == 1)
        d->rear = d->front;

    return 1;
}

int insertLast(Deque* d, int val){
    if(d->size == d->capacity) return 0;

    d->rear = (d->rear + 1) % d->capacity;
    d->arr[d->rear] = val;
    d->size++;
    return 1;
}

int deleteFront(Deque* d){
    if(d->size == 0) return 0;

    d->front = (d->front + 1) % d->capacity;
    d->size--;
    return 1;
}

int deleteLast(Deque* d){
    if(d->size == 0) return 0;

    d->rear = (d->rear - 1 + d->capacity) % d->capacity;
    d->size--;
    return 1;
}

int getFront(Deque* d){
    if(d->size == 0) return -1;
    return d->arr[d->front];
}

int getRear(Deque* d){
    if(d->size == 0) return -1;
    return d->arr[d->rear];
}

int main(){

    Deque* d = createDeque(3);

    insertLast(d,1);
    insertLast(d,2);
    insertFront(d,3);

    printf("%d\n", getRear(d));
    printf("%d\n", getFront(d));

    deleteLast(d);

    printf("%d\n", getRear(d));

    return 0;
}