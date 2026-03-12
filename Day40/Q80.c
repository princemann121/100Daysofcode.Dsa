/* Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead. */

#include <stdio.h>

#define MAX 1000

int main() {

    int n;
    scanf("%d",&n);

    int temp[MAX], ans[MAX], stack[MAX];
    int top = -1;

    for(int i=0;i<n;i++){
        scanf("%d",&temp[i]);
        ans[i] = 0;
    }

    for(int i=0;i<n;i++){

        while(top >= 0 && temp[i] > temp[stack[top]]){

            int idx = stack[top--];
            ans[idx] = i - idx;
        }

        stack[++top] = i;
    }

    for(int i=0;i<n;i++)
        printf("%d ", ans[i]);

    return 0;
}