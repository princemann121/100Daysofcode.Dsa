/* Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)
 */

 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;
int count = 0;

// push_front
void push_front(int x) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = front;

    if(front != NULL)
        front->prev = newNode;
    else
        rear = newNode;

    front = newNode;
    count++;
}

// push_back
void push_back(int x) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = rear;

    if(rear != NULL)
        rear->next = newNode;
    else
        front = newNode;

    rear = newNode;
    count++;
}

// pop_front
void pop_front() {
    if(front == NULL) {
        printf("Deque Empty\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    count--;
}

// pop_back
void pop_back() {
    if(rear == NULL) {
        printf("Deque Empty\n");
        return;
    }

    struct node* temp = rear;
    rear = rear->prev;

    if(rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    count--;
}

// front element
int getFront() {
    if(front == NULL) return -1;
    return front->data;
}

// rear element
int getBack() {
    if(rear == NULL) return -1;
    return rear->data;
}

// empty
int empty() {
    return front == NULL;
}

// size
int size() {
    return count;
}

// display
void display() {
    struct node* temp = front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    int n;
    scanf("%d",&n);

    while(n--) {

        int op, val;

        scanf("%d",&op);

        switch(op) {

            case 1:
                scanf("%d",&val);
                push_front(val);
                break;

            case 2:
                scanf("%d",&val);
                push_back(val);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                printf("%d\n", getFront());
                break;

            case 6:
                printf("%d\n", getBack());
                break;

            case 7:
                printf("%d\n", empty());
                break;

            case 8:
                printf("%d\n", size());
                break;

            case 9:
                display();
                break;
        }
    }

    return 0;
} 