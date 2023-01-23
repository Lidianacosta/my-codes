#include<stdio.h>
#include<math.h>


void calcula_hexagono(float l, float *area, float *perimetro);

int main(){

float A,P,l;

printf("digite o lado do hexagono\n");
scanf("%f",&l);

calcula_hexagono(l,&A,&P);

printf("A: %f P: %f",A,P);

    return(0);
}

void calcula_hexagono(float l, float *area, float *perimetro){


*area = (3*pow(2,l)*sqrt(3))/2;
*perimetro = 6*l ;


}