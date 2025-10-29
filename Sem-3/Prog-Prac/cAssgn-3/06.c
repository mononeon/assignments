#include <stdio.h>

struct Student {
    int roll;
    int score;
};

void input(struct Student *s) {
    printf("Enter roll and score: ");
    scanf("%d %d",&s->roll,&s->score);
}
void show(struct Student s) {
    printf("Roll=%d Score=%d\n",s.roll,s.score);
}
void modifyScore(struct Student *s, int newScore) {
    s->score=newScore;
}

int main() {
    struct Student s;
    input(&s);
    show(s);
    modifyScore(&s,95);
    show(s);
    return 0;
}
