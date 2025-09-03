#include<stdio.h>

int main(){
	int x;
	int y;
	scanf("%d", &x);
	scanf("%d", &y);
	int temp;
	temp = x;
	x = y;
	y = temp;
	printf("The numbers after swapping are x = %d and y = %d\n", x, y);
	
}
