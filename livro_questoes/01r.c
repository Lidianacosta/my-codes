#include<stdio.h>

void func_mostra_numeros(int n);

int main(void){
    int n = 4;
    func_mostra_numeros(n);
    return(0);
}

void func_mostra_numeros(int n){
    printf("% d",n);
    if(n > 0){
        func_mostra_numeros(n-1);
        printf(" * ");
    }
}