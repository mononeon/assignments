#include <stdio.h>

struct Student {
    int roll;
    char name[50], course[50], date[20];
    int marks[5];
    int hasMarks;
};

int count=0;

void admission(struct Student *s) {
    printf("Enter roll name course date: ");
    scanf("%d %s %s %s",&s->roll,s->name,s->course,s->date);
    s->hasMarks=0;
    count++;
}
void receiveMarks(struct Student *s) {
    printf("Enter 5 marks: ");
    for(int i=0;i<5;i++) scanf("%d",&s->marks[i]);
    s->hasMarks=1;
}
void markSheet(struct Student s) {
    if(!s.hasMarks) printf("Marks not available\n");
    else {
        printf("Roll %d Marks: ",s.roll);
        for(int i=0;i<5;i++) printf("%d ",s.marks[i]);
        printf("\n");
    }
}
