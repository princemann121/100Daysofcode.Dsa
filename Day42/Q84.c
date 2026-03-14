/* The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted. */

#include <stdio.h>

#define MAX 1000

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b){
    int t=*a; *a=*b; *b=t;
}

/* -------- MAX HEAP -------- */

void maxUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(maxHeap[p] < maxHeap[i]){
            swap(&maxHeap[p],&maxHeap[i]);
            i=p;
        } else break;
    }
}

void maxDown(int i){
    while(1){
        int l=2*i+1, r=2*i+2, largest=i;

        if(l<maxSize && maxHeap[l] > maxHeap[largest])
            largest=l;

        if(r<maxSize && maxHeap[r] > maxHeap[largest])
            largest=r;

        if(largest!=i){
            swap(&maxHeap[i],&maxHeap[largest]);
            i=largest;
        } else break;
    }
}

/* -------- MIN HEAP -------- */

void minUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(minHeap[p] > minHeap[i]){
            swap(&minHeap[p],&minHeap[i]);
            i=p;
        } else break;
    }
}

void minDown(int i){
    while(1){
        int l=2*i+1, r=2*i+2, smallest=i;

        if(l<minSize && minHeap[l] < minHeap[smallest])
            smallest=l;

        if(r<minSize && minHeap[r] < minHeap[smallest])
            smallest=r;

        if(smallest!=i){
            swap(&minHeap[i],&minHeap[smallest]);
            i=smallest;
        } else break;
    }
}

/* -------- ADD NUMBER -------- */

void addNum(int num){

    maxHeap[maxSize]=num;
    maxUp(maxSize);
    maxSize++;

    int val=maxHeap[0];
    maxHeap[0]=maxHeap[maxSize-1];
    maxSize--;
    maxDown(0);

    minHeap[minSize]=val;
    minUp(minSize);
    minSize++;

    if(minSize > maxSize){
        val=minHeap[0];
        minHeap[0]=minHeap[minSize-1];
        minSize--;
        minDown(0);

        maxHeap[maxSize]=val;
        maxUp(maxSize);
        maxSize++;
    }
}

/* -------- FIND MEDIAN -------- */

double findMedian(){

    if(maxSize > minSize)
        return maxHeap[0];

    return (maxHeap[0] + minHeap[0]) / 2.0;
}

int main(){

    int n;
    scanf("%d",&n);

    while(n--){

        int op;
        scanf("%d",&op);

        if(op==1){
            int x;
            scanf("%d",&x);
            addNum(x);
        }

        else if(op==2){
            printf("%.2f\n", findMedian());
        }
    }

    return 0;
}