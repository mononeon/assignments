/*
Write a program that converts a string like “123” to integer 123. Do not use any string library
function.
*/

#include<stdio.h>

int stringToInteger(char* str) {
    int i = 0, result = 0;

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}

int main() {
    char str[100];

    printf("Enter an numeric string: ");
    scanf("%s", str);
    
    int number = stringToInteger(str);

    printf("The numeric form of the string: %d\n", number);
    
    return 0;
}