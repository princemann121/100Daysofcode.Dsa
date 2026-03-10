/* You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7 */

 #include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {

    int nums[MAX], deque[MAX];
    int n, k;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    int front = 0, rear = -1;

    for(int i = 0; i < n; i++) {

        // Remove elements outside window
        if(front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements
        while(front <= rear && nums[deque[rear]] <= nums[i])
            rear--;

        deque[++rear] = i;

        // Print max when window is ready
        if(i >= k - 1)
            printf("%d ", nums[deque[front]]);
    }

    return 0;
}