/*
Suppose we do a binary search in the list [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32] for the value 23. To show and implement how the values of lower,upper, and mid change during the search, until and including the point where the base case is reached.

Aim:
To demonstrate a binary search in a sorted list for a specific target value, illustrating how the values of lower, upper, and mid change during the search until reaching the base case.

Algorithm:
1.Initialize the array: Create a sorted array [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32].
2.Initialize search parameters:
    Set the target value to 23.
    Set the lower bound (lower) to the beginning of the array (0).
    Set the upper bound (upper) to the end of the array (length - 1).
3.Binary Search:
    While the lower bound is less than or equal to the upper bound:
        Calculate the middle index (mid) using the formula mid = lower + (upper - lower) / 2.
        Print the current values of lower, upper, and mid.
        If the value at the mid index equals the target:
        Return the index of the target (mid) as it is found.
        If the value at the mid index is less than the target:
        Update the lower bound to mid + 1 and search in the right half.
        If the value at the mid index is greater than the target:
        Update the upper bound to mid - 1 and search in the left half.
4.Base Case:
    If the loop exits without finding the target, return -1 to indicate that the target is not present in the array.
5.Print Result:
    In the main function, print the index where the target was found or a message indicating that the target was not found.
*/

#include <stdio.h>

int binarySearch(int arr[], int target, int lower, int upper) {
    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;

        // Print the current values of lower, upper, and mid
        printf("Lower: %d, Upper: %d, Mid: %d\n", lower, upper, mid);

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            lower = mid + 1; // Search in the right half
        } else {
            upper = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32};
    int target = 23;
    int lower = 0;
    int upper = sizeof(arr) / sizeof(arr[0]) - 1;

    int result = binarySearch(arr, target, lower, upper);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}