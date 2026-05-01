//Capacity To Ship Packages Within D Days

bool isPossible(int* weights, int n, int days, int capacity) {
    int d = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + weights[i] > capacity) {
            d++;
            sum = weights[i];
            if (d > days)
                return false;
        } else {
            sum += weights[i];
        }
    }
    return true;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int max = weights[0], sum = 0;

    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > max)
            max = weights[i];
        sum += weights[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}