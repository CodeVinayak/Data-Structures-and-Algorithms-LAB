/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times. Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.
Example
There are  and  cylinders in the three stacks, with their heights in the three arrays. Remove the top 2 cylinders from  (heights = [1, 2]) and from  (heights = [1, 1]) so that the three stacks all are 2 units tall. Return  as the answer.

Aim:
To find the maximum possible height of three stacks of cylinders such that all three stacks are exactly the same height after removing any number of cylinders from the top.

Algorithm: Maximum Height of Equal Stacks
1.Initialize Stacks:
    Create three stacks of cylinders, each represented by an array of heights.
2.Calculate Cumulative Heights:
    For each stack, calculate the cumulative height from bottom to top.
3.Find Common Heights:
    Identify the common heights present in all three stacks. These are potential heights at which the stacks can be made equal.
4.Iterate through Common Heights:
    For each common height:
    Remove cylinders from the top of each stack until their heights match the common height.
    Calculate the total height at this common level.
5.Return Maximum Height:
    Return the maximum height calculated in step 4.
*/
#include <stdio.h>

// Function to find the maximum possible height of equal stacks
int equalStacks(int stack1[], int size1, int stack2[], int size2, int stack3[], int size3) {
    int height1 = 0, height2 = 0, height3 = 0;

    // Calculate cumulative heights of each stack
    for (int i = size1 - 1; i >= 0; i--)
        stack1[i] += (i + 1 < size1) ? stack1[i + 1] : 0;
    
    for (int i = size2 - 1; i >= 0; i--)
        stack2[i] += (i + 1 < size2) ? stack2[i + 1] : 0;

    for (int i = size3 - 1; i >= 0; i--)
        stack3[i] += (i + 1 < size3) ? stack3[i + 1] : 0;

    // Find common heights and calculate maximum height
    for (int i = 0; i < size1; i++) {
        if (stack1[i] == stack2[i] && stack2[i] == stack3[i])
            return stack1[i];
    }

    return 0; // If no common height is found
}

// Example usage in the main function
int main() {
    int stack1[] = {3, 2, 1, 1, 1};
    int stack2[] = {4, 3, 2};
    int stack3[] = {1, 1, 4, 1};

    int size1 = sizeof(stack1) / sizeof(stack1[0]);
    int size2 = sizeof(stack2) / sizeof(stack2[0]);
    int size3 = sizeof(stack3) / sizeof(stack3[0]);

    int result = equalStacks(stack1, size1, stack2, size2, stack3, size3);

    printf("Maximum possible height of equal stacks: %d\n", result);

    return 0;
}
