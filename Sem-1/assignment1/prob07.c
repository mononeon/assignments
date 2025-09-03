#include<stdio.h>

int check(float x, float avg){
	if (x > avg) printf("%f is greater than %f\n", x, avg);
	else if (x < avg) printf("%f is less than %f\n", x, avg);
	else printf("%f is equal to %f\n", x, avg);
}


int main(){
	float x;
	float y;
	float z;
	printf("Enter three integers: ");
	scanf("%f%f%f", &x, &y, &z);
	float avg;
	avg = (x+y+z)/3.0;
	printf("The average is: %f\n", avg);
	check(x, avg);
	check(y, avg);
	check(z, avg);
}
