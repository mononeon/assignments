#include <stdio.h>

int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    int fact = 1;
    while(n){
        fact *= n--;
    }
    printf("The factorial is: %d\n", fact);
    return 0;
}
