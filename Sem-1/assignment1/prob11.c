#include<stdio.h>

int main(){
    int a[5];
    for (int i=1; i<=5; i++){
        printf("Enter marks of subject%d: ", i);
        scanf("%d", &a[i-1]);
        if (a[i-1]>100 || a[i-1]<0){
            printf("Error input\n");
            return;
        }
    }
    int sum = 0;
    for(int i=0; i<5; i++){
        sum += a[i];
    }
    printf("Aggregate marks: %d\n", sum);
    printf("Percentage marks: %f\n", sum/5.0);
    return 0;
}