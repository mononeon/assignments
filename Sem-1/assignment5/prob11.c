#include <stdio.h>
#include <string.h>
 
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
 
    char line[256];
    int intCount = 0, floatCount = 0, charCount = 0, doubleCount = 0;
 
    while (fgets(line, sizeof(line), input)) {
        if (strstr(line, "int ")) intCount++;
        if (strstr(line, "float ")) floatCount++;
        if (strstr(line, "char ")) charCount++;
        if (strstr(line, "double ")) doubleCount++;
    }
 
    fclose(input);
 
    printf("int: %d\n", intCount);
    printf("float: %d\n", floatCount);
    printf("char: %d\n", charCount);
    printf("double: %d\n", doubleCount);
 
    return 0;
}