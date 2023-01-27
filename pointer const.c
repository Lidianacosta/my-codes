#include<stdio.h>

int main(){

int a=5,b=6 ;
const int *p=&a;

p = &b;

printf("%d",*p);







}