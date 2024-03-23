/* Radix Sort algorithm:
1.	Find the maximum element in the array to determine the number of digits in the largest element.
2.	Initialize a counter array with a size equal to the number of digits (typically 10 for decimal numbers) and set all values to 0.
3.	Iterate through each digit position, starting from the least significant digit (rightmost) to the most significant digit (leftmost).
4.	For each digit position, iterate through the array and update the counter array by counting the occurrence of each digit in that position.
5.	Update the counter array by adding the previous count to the current count, creating a cumulative sum of counts.
6.	Create a temporary output array to store the sorted elements.
7.	Iterate through the array from right to left.
o	Find the digit at the current position.
o	Use the counter array to determine the correct position in the output array for the current element based on the digit.
o	Decrement the count for that digit in the counter array.
o	Place the current element in the correct position in the output array.
8.	Copy the elements from the output array back to the original array.
9.	Repeat steps 3 to 8 for each subsequent digit position, from right to left.
10.	The array is now sorted in ascending order.
*/
#include <stdio.h>

// Function to find the maximum element in the array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit position
void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains the sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n)
{
    // Find the maximum element to determine the number of digits
    int max = getMax(arr, n);

    // Perform counting sort for every digit position
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
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
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Array after sorting: \n");
    printArray(arr, n);

    return 0;
}
