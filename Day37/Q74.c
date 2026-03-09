/* You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int heap[MAX];
int size = 0;
int k;

// Swap helper
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(int i){
    while(i > 0){
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]){
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

// Heapify down
void heapifyDown(int i){
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

// Insert element
void push(int val){
    heap[size] = val;
    heapifyUp(size);
    size++;
}

// Remove smallest
void pop(){
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
}

// Add new score and return kth largest
int add(int val){

    push(val);

    if(size > k)
        pop();

    return heap[0];
}

int main(){

    int n;

    printf("Enter k: ");
    scanf("%d",&k);

    printf("Enter initial number of scores: ");
    scanf("%d",&n);

    printf("Enter scores:\n");

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        add(x);
    }

    int q;

    printf("Enter number of new scores: ");
    scanf("%d",&q);

    while(q--){
        int val;
        scanf("%d",&val);

        printf("kth largest = %d\n", add(val));
    }

    return 0;
}