#include<stdio.h>

int multiplicacao(int a ,int b){
    return(a*b);
}

int soma(int a , int b){
    return(a+b);
}

int calcula(int x , int y , int (*operacao)(int, int)){

return((*operacao)(x,y));

}

int main(){

 int resultado = calcula(5,3,soma);

int resultado_m = calcula(5,3,multiplicacao);;

 printf("%d\n",resultado);
 printf("%d",resultado_m);


    return(0);
}