#include<stdio.h>

int main(){
    printf("Enter amount in rupees: ");
    int x;
    scanf("%d", &x);
    int a = x/100;
    x = x%100;
    int b = x/50;
    x = x%50;
    int c = x/10;
    int change = x%10;
    if (change != 0){
    	printf("Error input\n");
	return;
    }
    printf("Notes in 100: %d\nNotes in 50: %d\nNotes in 10: %d\nRemaining: %d\n", a, b, c, change);
}
