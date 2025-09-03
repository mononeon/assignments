#include <stdio.h>
#include <string.h>

struct Applicant {
    int id;
    char name[100];
    float score;
};

int lastId=0;

void input(struct Applicant *a) {
    a->id=++lastId;
    printf("Enter name: ");
    scanf("%s",a->name);
    printf("Enter score: ");
    scanf("%f",&a->score);
}
void show(struct Applicant a) {
    printf("ID=%d Name=%s Score=%.2f\n",a.id,a.name,a.score);
}
