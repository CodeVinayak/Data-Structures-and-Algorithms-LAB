#include <stdio.h>  
void selection(int arr[], int n)  
{  
int i, j, small;  
for (i = 0; i < n-1; i++)   
{  
    small = i; 
    for (j = i+1; j < n; j++)  
    if (arr[j] < arr[small])  
    small = j;  
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
}  
}  
void printArr(int a[], int n) 
{  
    int i;  
    for (i = 0; i < n; i++)  
    printf("%d ", a[i]);  
}  
int main()  
{  
    int a[] = { 12, 31,35, 25, 8, 32, 17 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Size of array is : %d\n",n);  
    printf("unsorted array is : ");  
    printArr(a, n);  
    printf("\nsorted array is : ");  
    selection(a, n);  
    printArr(a, n);  
    return 0;  
}    