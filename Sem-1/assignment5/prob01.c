#include<stdio.h>


typedef struct {
    int rollNumber;
    char name[50];
    char department[30];
    char course[30];
    int yearOfJoining;
} Student;

void printStudentByYear(Student *students, int numberOfStudents, int year) {
    printf("Students who joined in the year %d\n", year);
    int found = 0;
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i].yearOfJoining == year) {
            printf("- %s\n", students[i].name);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No students found in the year %d\n", year);
    }
}

void printStudentByRollNumber(Student *students, int numberOfStudents, int rollNumber) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student data for roll number %d\n", rollNumber);
            printf("- Name : %s\n", students[i].name);
            printf("- Department : %s\n", students[i].department);
            printf("- Course : %s\n", students[i].course);
            printf("- Year of Joining : %d\n", students[i].yearOfJoining);
            return;
        }
    }

    printf("There is no student with roll number %d./n", rollNumber);
}

int main() {
    Student students[] = {
        {1, "Rupam", "CSE", "V", 2021},
        {2, "Subham", "Rizzology", "RIzzologics", 2022},
        {3, "Ayush", "Chem", "B.Tech", 2023},
        {4, "Rihan", "Electrical", "EE", 2024},
        {5, "Piyas", "Arch", "B.Arch", 2022}
    };

    int numberOfStudents = 5;
    int yearOfJoiningToSearch = 2022;
    printf("\n");
    int rollNumberToSearch = 3;
    
    printStudentByYear(students, numberOfStudents, yearOfJoiningToSearch);
    printStudentByRollNumber(students, numberOfStudents, rollNumberToSearch);
    printf("\n");
    return 0;
}