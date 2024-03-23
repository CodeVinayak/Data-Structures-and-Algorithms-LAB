#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function to evaluate the expression
int evaluateExpression(char exp[]) {
    int result = 0;
    int num = 0;
    int sign = 1; // To keep track of positive or negative sign
    int i = 0;

    while (exp[i] != '\0') {
        char currentChar = exp[i];

        if (isdigit(currentChar)) {
            // Convert the character to an integer and update the current number
            num = num * 10 + (currentChar - '0');
        } else if (currentChar == '+') {
            result += sign * num;
            sign = 1;
            num = 0;
        } else if (currentChar == '-') {
            result += sign * num;
            sign = -1;
            num = 0;
        } else if (currentChar == '*') {
            // Handle multiplication by getting the next number
            i++;
            int nextNum = 0;
            while (isdigit(exp[i])) {
                nextNum = nextNum * 10 + (exp[i] - '0');
                i++;
            }
            num *= nextNum;
            continue; // Continue to the next character
        } else if (currentChar == '(') {
            // Handle opening parenthesis
            int j = i + 1;
            int count = 1;
            while (exp[j] != '\0') {
                if (exp[j] == '(') {
                    count++;
                } else if (exp[j] == ')') {
                    count--;
                    if (count == 0) {
                        // Recursively evaluate the expression inside the parentheses
                        char subExpression[j - i - 1];
                        strncpy(subExpression, exp + i + 1, j - i - 1);
                        subExpression[j - i - 1] = '\0';
                        num = evaluateExpression(subExpression);
                        i = j;
                        break;
                    }
                }
                j++;
            }
        }
        i++;
    }

    // Add the last number to the result
    result += sign * num;
    return result;
}

int main() {
    char expression[] = "5*13-(7+2)+6";
    int result = evaluateExpression(expression);
    printf("Result of the expression: %d\n", result);
    return 0;
}
