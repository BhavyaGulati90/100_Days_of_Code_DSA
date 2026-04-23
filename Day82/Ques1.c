/*Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.

Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)

Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x*/

  #include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; 

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;   
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}