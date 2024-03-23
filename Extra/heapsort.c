/*
Heap Sort algorithm:
1.	Build a max-heap from the array: To build a max-heap, start from the last non-leaf node and heapify each subtree in a bottom-up manner. Heapify the subtree by comparing the root node with its left and right child and swapping them if necessary. Repeat this process for all non-leaf nodes until the entire array is in the form of a max-heap.
2.	Extract the maximum element: After building the max-heap, the maximum element will be at the root of the heap (arr[0]). Swap this element with the last element in the array (arr[n-1]), where n is the size of the array. Decrease the size of the heap by 1.
3.	Heapify the root: After extracting the maximum element, the array is no longer in the form of a max-heap. Heapify the root node to restore the max-heap property.
4.	Repeat steps 2 and 3: Repeat steps 2 and 3 until the size of the heap becomes 1. After each iteration, the maximum element will be placed at the end of the array.
5.	The array is now sorted in ascending order.
*/
#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Array after sorting: \n");
    printArray(arr, n);
    return 0;
}
