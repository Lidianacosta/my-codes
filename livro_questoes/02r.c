#include<stdio.h>

int fat(int n);

int main(void){
    int n;
    printf("digite o numero que queira saber o fatorial: ");
    scanf("%d",&n);
    int resultado = fat(n);
    printf("\no resultado de %d fatorial e %d\n",n,resultado);
    return(0);
}

int fat(int n){
    if(n == 0){
        printf("1");
        return(1);
    }else{
        printf("%d\t",(n*fat(n-1)));
        return(n*fat(n-1));
    }
}