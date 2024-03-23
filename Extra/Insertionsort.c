#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        // printf("key is :%d\n",key);
        // printf("i is :%d\n",i);
        int j = i - 1;
        // printf("j is : %d\n",j);

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    // printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
