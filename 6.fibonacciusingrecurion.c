#include <stdio.h>

int fibonacciusingrecursion(int num)
{
    if (num <= 1)
    {
        return num;
    }
    else
    {
        return fibonacciusingrecursion(num - 1) + fibonacciusingrecursion(num - 2);
    }
}

int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    
    for (int i = 0; i <=num; i++)
    {
        int output = fibonacciusingrecursion(i);
        printf("\n%d ", output);
    }
    
    return 0;
}
