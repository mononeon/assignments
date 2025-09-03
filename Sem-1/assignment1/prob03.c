#include<stdio.h>

int main(){
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
	int sum=0;
	for(int i=0; i<3; i++){
		sum += x%10;
		x = x/10;
	}
	printf("The sum of the digits is %d\n", sum);
	
}
