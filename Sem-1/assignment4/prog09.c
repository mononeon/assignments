/*
Write a C program which accepts a string from user and counts the number of words in it. Do not
use any string library function.
*/

#include <stdio.h>

int countWords(char* str) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }

    return count;
}

int main() {
    char str[200];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int wordCount = countWords(str);
    printf("Number of words: %d\n", wordCount);

    return 0;
}