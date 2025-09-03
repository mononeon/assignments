/*
Write a C program which accepts an integer and creates a string representation of the integer
value. Do not use any string library function. [Example: If the argument is integer 1234 the program
should form the string “1234”]
*/

#include<stdio.h>

void intToString(int number, char* str) {
    int isNegative;
    if (number < 0) {
        isNegative = 1;
        number = -number;
    }

    int i=0;
    do {
        str[i++] = (number%10) + '0';
        number /= 10;
    } while (number > 0);

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    for (int left = 0, right = i - 1; left < right; left++, right--) {
        char temp = str[right];
        str[right] = str[left];
        str[left] = temp;
    }
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    char str[12];
    intToString(number, str);

    printf("String representation: %s\n", str);

    return 0;
}