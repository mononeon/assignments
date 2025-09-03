#include <stdio.h>
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
 
    FILE *input = fopen(argv[1], "r");
 
    if (input == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
 
    char c, prev = '\0';
    int inComment = 0, totalChars = 0, commentChars = 0;
 
    while ((c = fgetc(input)) != EOF) {
        totalChars++;
 
        if (!inComment && c == '/' && prev == '/') {
            // Single-line comment
            while ((c = fgetc(input)) != EOF && c != '\n') {
                totalChars++;
                commentChars++;
            }
            prev = '\0';
            continue;
        } else if (!inComment && c == '*' && prev == '/') {
            // Start of multi-line comment
            inComment = 1;
        } else if (inComment && c == '/' && prev == '*') {
            // End of multi-line comment
            inComment = 0;
            commentChars += 2; // Count '*' and '/'
            prev = '\0';
            continue;
        }
 
        if (inComment) {
            commentChars++;
        }
 
        prev = c;
    }
 
    fclose(input);
 
    if (totalChars == 0) {
        printf("File is empty.\n");
    } else {
        float percentage = (float)commentChars / totalChars * 100;
        printf("Percentage of characters in comments: %.2f%%\n", percentage);
    }
 
    return 0;
}