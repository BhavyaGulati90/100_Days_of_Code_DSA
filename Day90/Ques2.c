// Split Array Largest Sum

#include <stdio.h>

int canSplit(int nums[], int n, int k, int maxSum) {
    int count = 1, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + nums[i] <= maxSum) {
            curr += nums[i];
        } else {
            count++;
            curr = nums[i];
            if (count > k) return 0;
        }
    }
    return 1;
}

int splitArray(int nums[], int n, int k) {
    int low = nums[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > low) low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canSplit(nums, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
 