/* Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated */


#include <stdio.h>          // Header file for input/output functions like scanf, printf
#define MAX_SIZE 100        // Define maximum size of the array

int main() {
    int n, arr[MAX_SIZE], pos, x;  
    // n = number of elements
    // arr = array to store elements
    // pos = position where new element will be inserted
    // x = value to be inserted

    scanf("%d", &n);  
    // Take input for number of elements in the array

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  
        // Input array elements one by one
    }

    scanf("%d", &pos);  
    // Input position (1-based index) where element is to be inserted

    scanf("%d", &x);    
    // Input the value to be inserted

    int index = pos - 1;  
    // Convert 1-based position to 0-based index (array starts from 0)

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];  
        // Shift elements to the right to create space for new element
    }

    arr[index] = x;  
    // Insert the new element at the correct index

    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);  
        // Print updated array (size becomes n+1 after insertion)
    }

    printf("\n");  
    // Print newline for better output formatting

    return 0;  
    // End of program
}
