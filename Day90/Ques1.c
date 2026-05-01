/*Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.*/

#include <stdio.h>

int can_paint(int boards[], int n, int k, int max_time) {
    int painters = 1, curr_time = 0;
    for (int i = 0; i < n; i++) {
        if (curr_time + boards[i] <= max_time) {
            curr_time += boards[i];
        } else {
            painters++;
            curr_time = boards[i];
            if (painters > k) return 0;
        }
    }
    return 1;
}

int min_time(int boards[], int n, int k) {
    int low = boards[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (can_paint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", min_time(boards, n, k));
    return 0;
}