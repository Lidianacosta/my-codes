#include<stdio.h>

int mdc(int a,int b);

int main(void){
    int x,y,resultado;
    printf("digite os numeros que esta querendo saber o mdc: ");
    scanf("%d %d",&x,&y);
    resultado = mdc(x,y);
    printf("o mdc de %d e %d e %d",x,y,resultado);
    return(0);
}

int mdc(int a,int b){
    int r = a % b;
    if(r == 0){
        return(b);
    }else{
        return(mdc(b,r));
    }
}