/******************************************************************************
Question:Create an array named "numbers" with the following values: [1, 2, 3, 4, 5]. Create a pointer variable named "ptr" and assign it the memory address of the first element of the array. Perform the following operations:
a) Insert the value 6 at the memory location pointed to by "ptr".
b) Delete the value stored in the memory location pointed to by "ptr".
Name: Vinayak Kumar Singh
Registeration Number: 23MCA1030
*******************************************************************************/
#include <stdio.h>
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr = &numbers[0]; // first element to "ptr"
    // a) Insert the value 6 at the memory location pointed to by "ptr".
    *ptr = 6;
    printf("array after insertion: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    // b) Delete the value stored in the memory location pointed to by "ptr".
    *ptr = 0;
    printf("array after deletion: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
