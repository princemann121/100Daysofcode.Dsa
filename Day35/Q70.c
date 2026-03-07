/* Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void push(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

int transfer(MyQueue* obj) {
    while(obj->top1 != -1) {
        obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
    }
}

int pop(MyQueue* obj) {

    if(obj->top2 == -1)
        transfer(obj);

    if(obj->top2 == -1) {
        printf("Queue Empty\n");
        return -1;
    }

    return obj->stack2[obj->top2--];

}

int peek(MyQueue* obj) {

    if(obj->top2 == -1)
        transfer(obj);

    return obj->stack2[obj->top2];
}

bool empty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
int main() {

    MyQueue* obj = myQueueCreate();

    push(obj, 10);
    push(obj, 20);

    printf("%d\n", peek(obj)); // 10
    printf("%d\n", pop(obj));  // 10
    printf("%d\n", empty(obj)); // 0 (false)

    myQueueFree(obj);

    return 0;
}