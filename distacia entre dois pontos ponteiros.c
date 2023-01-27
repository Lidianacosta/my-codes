#include<stdio.h>
#include<math.h>

void calcular_distancia(float *distancia, float x1,float y1 , float x2, float y2){

*distancia = sqrt(pow(y2 - y1,2)+ pow(x2 - x1,2));


}


int main(){

 float x1,x2,y1,y2,distancia;

x1 = x2 = y1 = y2 = 10;


calcular_distancia(&distancia,9.0,3.0,2.0,8.0);


printf("%.1f",distancia);

    return(0);
}

