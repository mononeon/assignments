/*
Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and
zero otherwise.
*/

#include <stdio.h>

#include <stdio.h>

int strend(char s[], char t[]) {
    int i, j;

    for (i = 0; s[i] != '\0'; i++);
    for (j = 0; t[j] != '\0'; j++);
    
    if (j > i) {
        return 0;
    }

    for (int k = 0; k < j; k++) {
        if (s[i - j + k] != t[k]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char s[100], t[100];
    
    printf("Enter the main string: ");
    fgets(s, sizeof(s), stdin);
    printf("Enter the substring: ");
    fgets(t, sizeof(t), stdin);

    if (strend(s, t)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}