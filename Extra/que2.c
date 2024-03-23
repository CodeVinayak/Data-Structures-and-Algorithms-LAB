/******************************************************************************
Question:Create a function named "calculateSum" that takes two parameters, "a" and "b". The function should return the sum of "a" and "b". Perform the following operations:
a) Call the function with the values 5 and 7.
b) Insert a new parameter "c" to the function and modify it to return the sum of "a", "b", and "c". Call the function with the values 2, 4, and 6.
Name: Vinayak Kumar Singh
Registeration Number: 23MCA1030
*******************************************************************************/
#include <stdio.h>
int
calculateSum (int a, int b)
{
  return a + b;
}

int
calculateSumWithC (int a, int b, int c)
{
  return a + b + c;
}

int
main ()
{
  // a) Call the function with the values 5 and 7.
  int result1 = calculateSum (5, 7);
  printf ("Result 1: %d\n", result1);
  // b) Call the function with the values 2, 4, and 6.
  int result2 = calculateSumWithC (2, 4, 6);
  printf ("Result 2: %d\n", result2);
  return 0;
}
