// Sliding Window Maximum

#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* ans = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* dq = (int*)malloc(numsSize * sizeof(int));  
    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        while (front <= rear && dq[front] <= i - k) {
            front++;
        }

        while (front <= rear && nums[dq[rear]] < nums[i]) {
            rear--;
        }

        dq[++rear] = i;

        if (i >= k - 1) {
            ans[idx++] = nums[dq[front]];
        }
    }

    free(dq);
    *returnSize = idx;
    return ans;
}