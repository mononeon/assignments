/*
Write a C function which accepts a string str1 and returns a new string str2 which is str1 with
each word reversed. Do not use any string library function.
*/

#include <stdio.h>
#include <stdlib.h>

void reverseWord(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* reverseWordsInString(char* str1) {
    int length = 0;
    while (str1[length] != '\0') {
        length++;
    }

    if (length > 0 && str1[length - 1] == '\n') {
        str1[--length] = '\0';
    }

    char* str2 = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i <= length; i++) {
        str2[i] = str1[i];
    }

    int start = 0;
    for (int i = 0; i <= length; i++) {
        if (str2[i] == ' ' || str2[i] == '\0') {
            reverseWord(str2, start, i - 1);
            start = i + 1;
        }
    }

    return str2;
}

int main() {
    char str1[200];
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    char* str2 = reverseWordsInString(str1);
    printf("Reversed words: %s\n", str2);

    free(str2);
    return 0;
}