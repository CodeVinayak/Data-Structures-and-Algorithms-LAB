/* Given an array of integers nums, sort the array in ascending order and return it. You must solve the problem without using any built-in functions in O(nlogNo) time complexity and with the smallest space complexity possible.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Aim:
To sort an array of integers in ascending order using in-place merge sort without using any built-in functions. Achieve O(nlogn) time complexity and the smallest possible space complexity.

Algorithm:
1.Base Case:
    If the array has one or zero elements, it is already sorted, and no further action is needed.
2.Split Array:
    Divide the array into two halves: left and right.
3.Recursively Sort:
    Recursively apply the merge sort algorithm to the left and right halves.
4.Merge:
    Merge the two sorted halves to produce a single sorted array.
*/
#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}

// Function to implement in-place merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Example usage in the main function
int main() {
    int nums[] = {5, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    // Call the mergeSort function to sort the array
    mergeSort(nums, 0, size - 1);

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
