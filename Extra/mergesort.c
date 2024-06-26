/* MergeSort
1.	Start with an unsorted array of elements.
2.	Divide the array into two halves.
3.	Recursively apply steps 2-3 to each half until each sub-array contains only one element or is empty.
4.	Merge the sorted sub-arrays to obtain a single sorted array
*/

#include <stdlib.h>
#include <stdio.h>
// Merge Function
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Merge Sort Function in C
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// Functions to Print Elements of Array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", A[i]);
}
// Main Method
int main()
{
    int arr[] = {85, 24, 63, 45, 17, 31, 96, 50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is : ");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is : ");
    printArray(arr, arr_size);
    return 0;
}
