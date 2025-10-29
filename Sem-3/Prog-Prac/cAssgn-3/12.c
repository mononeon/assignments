#include <stdio.h>
#include <string.h>

struct Item {
    int code, qty;
    char name[50];
    float rate;
};

struct Item list[50];
int n=0;

void add(struct Item it) {
    for(int i=0;i<n;i++) if(list[i].code==it.code) {
        printf("Duplicate code!\n"); return;
    }
    list[n++]=it;
}
void changeRate(int code,float r) {
    for(int i=0;i<n;i++) if(list[i].code==code) list[i].rate=r;
}
void issue(int code,int q) {
    for(int i=0;i<n;i++) if(list[i].code==code && list[i].qty>=q) list[i].qty-=q;
}
void receive(int code,int q) {
    for(int i=0;i<n;i++) if(list[i].code==code) list[i].qty+=q;
}
void price(int code) {
    for(int i=0;i<n;i++) if(list[i].code==code)
        printf("Stock value=%.2f\n",list[i].rate*list[i].qty);
}
