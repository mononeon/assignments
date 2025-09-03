/*
Write a program to count the number of occurrences of any two vowels in succession in a line of
text.
*/

#include <stdio.h>

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    char str[1000];
    int count = 0;

    printf("Enter a line of text: ");
    scanf("%[^\n]", str);

    for (int i = 0; str[i+1] != '\0'; i++) {
        if (isVowel(str[i]) && isVowel(str[i+1])) {
            count++;
        }
    }

    printf("The number of occurrences of two consecutive vowels: %d\n", count);
    
    return 0;
}