#include<stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void){
    int a = 20,b = 4,r;
    r = MAX(a,b);
    printf("%d\n",r);   
    return(0);
}

//verifica qual é o maior número.