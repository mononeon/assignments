#include <stdio.h>
 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }
 
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
 
    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
 
    char c, prev = '\0';
    int inComment = 0;
 
    while ((c = fgetc(input)) != EOF) {
        if (!inComment && c == '/' && prev == '/') {
            // Single-line comment
            while ((c = fgetc(input)) != EOF && c != '\n');
            prev = '\0';
            continue;
        } else if (!inComment && c == '*' && prev == '/') {
            // Start of multi-line comment
            inComment = 1;
        } else if (inComment && c == '/' && prev == '*') {
            // End of multi-line comment
            inComment = 0;
            prev = '\0';
            continue;
        }
 
        if (!inComment && prev != '\0') {
            fputc(prev, output);
        }
 
        prev = c;
    }
 
    if (!inComment && prev != '\0') {
        fputc(prev, output);
    }
 
    fclose(input);
    fclose(output);
 
    printf("Comments removed successfully.\n");
    return 0;
}