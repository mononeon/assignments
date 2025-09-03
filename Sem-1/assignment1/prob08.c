#include<stdio.h>


int main(){
	float cent;
	float fahr;
	printf("Enter temparature in Fahrenheit degrees: ");
	scanf("%f", &fahr);
	cent = 5.0 * (fahr-32.0)/9.0;
	printf("The temparature in Centigrade degrees is: %f\n", cent);
}	
