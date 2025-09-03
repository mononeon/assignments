#include<stdio.h>

int main(){
	int x, y, z;
	printf("Enter 3 numbers: ");
	scanf("%d%d%d", &x, &y, &z);
	if (x>=y && x >= z)
	{
		printf("The maximum number is: %d\n", x);
		if (y>=z) printf("The minimum number is: %d\n", z);
		else printf("The minimum number is: %d\n", y);
	}	
	else if (y>=z &&  y>=x)
	{
		printf("The maximum number is: %d\n", y);
		if (z>=x) printf("The minimum number is: %d\n", x);
		else printf("The minimum number is: %d\n", z);
	}
	else
	{
		printf("The maximum number is: %d\n", z);
		if (x>=y) printf("The minimum number is: %d\n", y);
		else printf("The minimum number is: %d\n", x);
	}
}
