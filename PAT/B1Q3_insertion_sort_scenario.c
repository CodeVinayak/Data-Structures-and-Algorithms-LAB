/*
Suppose you have an array of 1234 records in which only a few are out of order and they are not very far from their correct positions. Which sorting algorithm (among
merge, insertion, heap, quick, bubble, counting, and radix) would you see to put the whole array in order? Justify your choice and Implement the scenario.

Aim:
To sort an array of 1234 records using the Insertion Sort algorithm, considering that only a few records are out of order and they are not very far from their correct positions.

Algorithm:
1.Initialize the array:
Create an array of 1234 records, where only a few are out of order.
2.Initialize parameters:
Set the array size (n) to the length of the array.
3.Insertion Sort:
    Implement the Insertion Sort algorithm to rearrange the elements:
        Start a loop from the second element (i=1) to the end of the array.
        For each element at index i, compare it with the previous elements and move larger elements to one position ahead.
        Repeat until the correct position for the current element is found, ensuring that the array remains sorted.
4.Print Original and Sorted Arrays:
    In the main function, print the original array before sorting.
    Call the Insertion Sort function to sort the array.
    Print the sorted array after sorting.
*/
#include <stdio.h>

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 1,2,4,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
