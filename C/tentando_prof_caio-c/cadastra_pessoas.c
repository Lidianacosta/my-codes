// 1. Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
// armazene os dados em uma estrutura. Exiba os dados armazenados ao final. 

#include<stdio.h>
#include<stdlib.h>

typedef struct pessoa{
    char nome[50];
    int idade;
    char endereço[50];
}Pessoa;

void prencher(Pessoa *p,int n);
void imprimir(Pessoa *p,int n);

void main(void){
    int numeros_pessoas_cadastrar;
    printf("digite o numero de pessoas que deseja cadastrar: ");
    scanf("%d",&numeros_pessoas_cadastrar);

 Pessoa *pessoa = (Pessoa*)malloc(numeros_pessoas_cadastrar*sizeof(Pessoa));  

    prencher(pessoa,numeros_pessoas_cadastrar);
    imprimir(pessoa,numeros_pessoas_cadastrar);
}

void prencher(Pessoa *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("digite os dados: \n");
        printf("o nome: ");
        scanf(" %[^\n]s",p->nome);
        printf("a idade: ");
        scanf("%d",&p->idade);
        printf("endereco: ");
        scanf(" %[^\n]s",p->endereço);
    }
}

void imprimir(Pessoa *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("os dados: \n");
        printf("o nome: %s\n",p->nome);
        printf("a idade: %d\n",p->idade);
        printf("endereco: %s\n",p->endereço);
    }
}
