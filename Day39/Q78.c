/* Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order. */

#include <stdio.h>

#define MAX 1000

struct Node {
    int num;
    int freq;
};

int main() {

    int nums[MAX];
    int n, k;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    struct Node arr[MAX];
    int size = 0;

    // Count frequencies
    for(int i = 0; i < n; i++) {

        int found = 0;

        for(int j = 0; j < size; j++) {
            if(arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found) {
            arr[size].num = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    // Sort by frequency (descending)
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {

            if(arr[i].freq < arr[j].freq) {

                struct Node temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print top k
    for(int i = 0; i < k; i++)
        printf("%d ", arr[i].num);

    return 0;
}