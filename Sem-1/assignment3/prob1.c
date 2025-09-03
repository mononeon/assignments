#include <stdio.h>

int main() {
    int len;
    printf("Enter the number of elements to be entered: ");
    scanf("%d", &len);
    int a[len];
    for(int i=0;i<len;i++){
        printf("Element[%d]: ", i);
        scanf("%d", a+i);
    }
    printf("\n");
    for(int i=0;i<len;i++){
        printf("%d\n", *(a+len-i-1));
    }
    
}

