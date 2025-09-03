/*
Write a C program which accepts a string from user and checks whether it is palindrome or not.
Do not use any string library function. [Example of a palindrome string: "abcba", "abba"]
*/

#include <stdio.h>

int isPalindrome(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}