#include<stdio.h>

int main(){
	double length;
	double breadth;
	printf("Enter the length of the rectangle: ");
	scanf("%lf", &length);
	printf("Enter the breadth of the rectangle: ");	
	scanf("%lf", &breadth);
	printf("Area of the rectangle is %lf\n", length*breadth);
	printf("Perimeter of the rectangle is %lf\n", 2*(length+breadth));
	printf("Enter the radius of the circle: ");
	double radius;
	scanf("%lf", &radius);
	printf("Area of the circle is: %lf\n", 3.1415 * radius * radius);
	printf("Circumference of the circle is: %lf\n", 3.1415 * 2 * radius);
}
