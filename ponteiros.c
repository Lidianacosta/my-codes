#include<stdio.h>

void i(int *n){

   (*n)++;

}

int main(){
int n=5;

i(&n);

printf("%d",n);


    return(0);
}