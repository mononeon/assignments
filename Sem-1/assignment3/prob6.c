#include <stdio.h>

int main() {
    int marks[5][5], total[5] = {0}, highest = 0, highestIndex = 0;

    printf("Enter marks obtained by 5 students in 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
            total[i] += marks[i][j];
        }
        if (total[i] > highest) {
            highest = total[i];
            highestIndex = i;
        }
    }

    printf("Total marks obtained:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
    }

    printf("Highest total marks: %d (Student %d)\n", highest, highestIndex + 1);

    return 0;
}