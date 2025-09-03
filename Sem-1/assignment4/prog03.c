/*
Write a program that reads a line and converts it into all capitals without using any string library
function. (input string may also contain capital letters)
*/

#include <stdio.h>

int main() {
    char str[100];
    int i = 0;

    printf("Enter a line of text: \n");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }

    printf("%s", str);

    return 0;
}
