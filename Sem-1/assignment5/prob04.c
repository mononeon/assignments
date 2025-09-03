#include <stdio.h>
 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }
 
    FILE *source = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");
 
    if (source == NULL || dest == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
 
    char c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, dest);
    }
 
    fclose(source);
    fclose(dest);
 
    printf("File copied successfully.\n");
    return 0;
}