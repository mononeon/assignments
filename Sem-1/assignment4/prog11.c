/*
Write a function squeeze(s,c) which removes all occurrences of the character c from the string s.
*/

#include <stdio.h>

#include <stdio.h>

void squeeze(char *str, char c) {
    int i, j = 0;
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    
    str[j] = '\0';
}

int main() {
    char s[100];
    char c;
    
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);
    
    printf("Enter the character to remove: ");
    scanf("%c", &c);
    
    squeeze(s, c);
    
    printf("Modified string: %s", s);
    
    return 0;
}   