// 3. Fa¸ca um programa que recebe nomes de frutas e seu pre¸co. A quantidade frutas deve ser informada
// pelo o usu´ario. Utilize aloca¸c˜ao dinˆamica, especialmente a fun¸c˜ao realloc para n˜ao desperdi¸car
// mem´oria.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void){
 //================================================================
    int numero_frutas,linha;
    
    printf("digite quantas frutas vai ter\n");
    scanf("%d",&numero_frutas);
 //================================================================
    char **frutas = (char**)malloc(numero_frutas*sizeof(char*));
    if(frutas==NULL){ 
        printf("Erro");
        exit(1);
    } 
 //================================================================   
    for(linha =0;linha<numero_frutas;linha++){

     frutas[linha] = (char*)malloc(50*sizeof(char));

     if(frutas[linha]==NULL){ 
        printf("Erro");
        exit(1);
     } 
 
    }
 //================================================================
    float *preco  = (float *)malloc(numero_frutas*sizeof(float));

    for(linha =0;linha<numero_frutas;linha++){
     printf("digite o nome das frutas\n");
        scanf(" %[^\n]s",frutas[linha]);
     printf("digite o preco das frutas\n");
        scanf("%f",&preco[linha]);
     
    }

 //================================================================

    for(linha =0;linha<numero_frutas;linha++){
     
        frutas[linha]  = (char**)realloc(frutas[linha],(strlen(frutas[linha])+1)*sizeof(char*));
     
    }
 //================================================================
    for(linha =0;linha<numero_frutas;linha++){
     
        printf("o nome e : %s  ||",frutas[linha]);
        printf(" o preco e : %.2f\n",preco[linha]);
     
    }
 //================================================================
    for(linha = 0;linha<numero_frutas;linha++){

     free(frutas[linha]);

    }

    free(frutas);
    free(preco);
//================================================================
    return(0);
}