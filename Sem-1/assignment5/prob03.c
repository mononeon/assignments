#include <stdio.h>
#include <string.h>
 
#define NUM_STUDENTS 10
#define NUM_SUBJECTS 6
 
struct Student {
    char name[50];
    int roll;
    float marks[NUM_SUBJECTS];
    float average;
};
 
void calculateAverages(struct Student students[]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            sum += students[i].marks[j];
        }
        students[i].average = sum / NUM_SUBJECTS;
    }
}
 
void sortStudents(struct Student students[]) {
    struct Student temp;
    for (int i = 0; i < NUM_STUDENTS - 1; i++) {
        for (int j = 0; j < NUM_STUDENTS - i - 1; j++) {
            if (students[j].average > students[j + 1].average) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
 
void printRankList(struct Student students[]) {
    printf("Rank List:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Roll: %d, Name: %s, Average: %.2f\n", students[i].roll, students[i].name, students[i].average);
    }
}
 
int main() {
    struct Student students[NUM_STUDENTS];
 
    // Input student data
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name, roll, and marks for 6 subjects for student %d:\n", i + 1);
        scanf("%s %d", students[i].name, &students[i].roll);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            scanf("%f", &students[i].marks[j]);
        }
    }
 
    calculateAverages(students);
    sortStudents(students);
    printRankList(students);
 
    return 0;
}