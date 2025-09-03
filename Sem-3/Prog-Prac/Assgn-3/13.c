#include <stdio.h>

struct Balance {
    int acc;
    float bal;
    char date[20];
};

struct Transaction {
    int acc;
    char date[20];
    float amt;
    char type; // W/D
};

void apply(struct Balance *b, struct Transaction t) {
    if(b->acc!=t.acc) return;
    if(t.type=='D') b->bal+=t.amt;
    else if(t.type=='W') {
        if(b->bal>=t.amt) b->bal-=t.amt;
        else printf("Insufficient funds!\n");
    }
    strcpy(b->date,t.date);
}
