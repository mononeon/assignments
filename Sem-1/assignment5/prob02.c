#include <stdio.h>
 
int main() {
    FILE *fp;
    char c;
 
    fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
 
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
 
    fclose(fp);
    return 0;
}