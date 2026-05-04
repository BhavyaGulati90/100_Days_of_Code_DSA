// Kth Largest Element in an Array


#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;
    int low = 0, high = numsSize - 1;

    while (low <= high) {
        int pivot = nums[low + rand() % (high - low + 1)];

        int lt = low, i = low, gt = high;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[i], &nums[lt]);
                i++;
                lt++;
            } else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } else {
                i++;
            }
        }

        if (target < lt)
            high = lt - 1;
        else if (target > gt)
            low = gt + 1;
        else
            return nums[target];
    }

    return -1;
}