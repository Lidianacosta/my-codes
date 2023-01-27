#include<stdio.h>
#include<locale.h>

// ======================funções================================= 

float media(float a ,float b);
void calcula (float a , float b,float (*pointer)(float,float));

//===============================================================

int main(){
 setlocale(LC_ALL,"portuguese");
   
   float x,y;

   scanf("%f %f",&x,&y);

    calcula(x,y,media);
   
   
    return(0);
}

// ======================funções================================= 

void calcula (float a , float b,float (*pointer)(float,float)){

    printf("%.1f",pointer(a,b));

}
float media(float a ,float b){
    return(a+b)/2.0;
}
//===============================================================