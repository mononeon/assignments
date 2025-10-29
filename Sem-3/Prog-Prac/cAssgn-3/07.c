#include <stdio.h>
#include <string.h>

struct Time {
    int h,m,s;
};

void set24(struct Time *t, int h,int m,int s) {
    t->h=h; t->m=m; t->s=s;
}
void setAMPM(struct Time *t, int h,int m,int s,const char *p) {
    if(strcmp(p,"PM")==0 && h!=12) h+=12;
    if(strcmp(p,"AM")==0 && h==12) h=0;
    t->h=h; t->m=m; t->s=s;
}
void display24(struct Time t) {
    printf("%02d:%02d:%02d\n",t.h,t.m,t.s);
}
void displayAMPM(struct Time t) {
    char *p = (t.h>=12)?"PM":"AM";
    int h=(t.h%12==0)?12:t.h%12;
    printf("%02d:%02d:%02d %s\n",h,t.m,t.s,p);
}
void addMinute(struct Time *t,int m) {
    t->m+=m;
    t->h += t->m/60;
    t->m %= 60;
    t->h %= 24;
}
