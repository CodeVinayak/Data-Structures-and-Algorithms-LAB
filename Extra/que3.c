/*Create a pointer variable named "ptr" and assign it the memory address of an integer variable "num". Perform the following operations:
a) Insert the value 10 into the memory location pointed to by "ptr".
b) Delete the value stored in the memory location pointed to by "ptr"
*/
#include <stdio.h>
int main() {
    int num;  // Declare an integer variable named "num"
    int *ptr; // Declare a pointer variable named "ptr"

    // Assign the memory address of "num" to the pointer "ptr"
    ptr = &num;

    // Insert the value 10 into the memory location pointed to by "ptr"
    *ptr = 10;

    // Print the value stored in "num" to verify the change
    printf("The value of num is: %d\n", num);

    // Delete the value stored in the memory location pointed to by "ptr"
    *ptr = 0;

    // Print the value stored in "num" again to see the change after deletion
    printf("The value of num after deletion is: %d\n", num);

    return 0;
}
