#include<stdio.h>


int main(){
	int x;
	int y;
	printf("Enter two integers: ");
	scanf("%d%d", &x, &y);
	if (y > x){
		int temp = x;
		x = y;
		y = temp;
	}
	printf("Fractional number: %d/%d\n", x, y);
	printf("Real value number: %f\n", 1.0 * x/y);
}
