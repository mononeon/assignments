#include<stdio.h>
int main(){
    for(int i=0;i<255;i++){
        char c=i;
        printf("%d\t%c\n",c,c);
    }
    return 0;
}