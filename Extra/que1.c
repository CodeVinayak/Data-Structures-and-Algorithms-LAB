/******************************************************************************
Question:Create an array named "grades" with the following initial values: [85, 92, 76, 88, 95]. Perform the following operations:
a) Delete the value at the end of the array.
b) Insert the value 80 at the beginning of the array.
c) Insert the value 90 at index 3.
d) Delete the value at index 1.
Name: Vinayak Kumar Singh
Registeration Number: 23MCA1030

*******************************************************************************/
#include <stdio.h>
int main() {
    int grades[] = {85, 92, 76, 88, 95};
    int i, len = sizeof(grades) / sizeof(grades[0]);
    len--;
    for (i = len; i > 0; i--) {
        grades[i] = grades[i - 1];
    }
    grades[0] = 80;
    len++;
    for (i = len; i > 3; i--) {
        grades[i] = grades[i - 1];
    }
    grades[3] = 90;
    len++;
    for (i = 1; i < len - 1; i++) {
        grades[i] = grades[i + 1];
    }
    len--;
    for (i = 0; i < len; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");
    return 0;
}
