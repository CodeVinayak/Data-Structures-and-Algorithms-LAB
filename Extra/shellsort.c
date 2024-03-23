/*shell sort:
1.	Start with an unsorted array of elements.
2.	Define a gap sequence, which determines the gap between elements to be compared.
3.	Iterate over the gap sequence.
4.	For each gap, divide the array into sub-arrays of size gap.
5.	Sort each sub-array using an insertion sort algorithm.
6.	Decrease the gap and repeat steps 4-5 until the gap is 1.
7.	Finally, sort the entire array using the insertion sort algorithm.
*/
#include <stdio.h>

// Shell sort function
void shellSort(int arr[], int n)
{
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort on each gap
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array after sorting: \n");
    printArray(arr, n);

    return 0;
}
