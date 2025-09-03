#include <stdio.h>
#include <math.h>

int main() {
    double pi = 3.1415;
    double length, breadth;
    double radius, areaRectangle, perimeterRectangle, areaCircle, perimeterCircle, ratio;
    int choice;

    // Input length and breadth of the rectangle
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the breadth of the rectangle: ");
    scanf("%lf", &breadth);

    // Calculate area and perimeter of the rectangle
    areaRectangle = length * breadth;
    perimeterRectangle = 2 * (length + breadth);

    // Menu for user selection  
    printf("1. Calculate for equal areas: \n");
    printf("2. Calculate for equal perimeters: \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            // (i) Equal areas: Area of rectangle = Area of circle
            radius = sqrt(areaRectangle / pi);
            perimeterCircle = 2 * pi * radius;
            ratio = perimeterRectangle / perimeterCircle;

            printf("\n(i) Equal areas:\n");
            printf("Radius of the circle: %.2f\n", radius);
            printf("Ratio of perimeters (Rectangle/Circle): %.2f\n", ratio);
            break;

        case 2: 
            // (ii) Equal perimeters: Perimeter of rectangle = Perimeter of circle
            radius = perimeterRectangle / (2 * pi);
            areaCircle = pi * radius * radius;
            ratio = areaRectangle / areaCircle;

            printf("\n(ii) Equal perimeters:\n");
            printf("Radius of the circle: %.2f\n", radius);
            printf("Ratio of areas (Rectangle/Circle): %.2f\n", ratio);
            break;

        default:
            printf("Invalid choice! Please select 1 or 2.\n");
            break;
    }

    return 0;
}
