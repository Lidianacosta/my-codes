#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1

typedef struct 
{
    char nome[255];
    int matricula;
    int periodo;
    int turma;
    char curso[100];
}estudando;


int main(){
int count;
estudando *aluno = (estudando*)malloc(N*sizeof(estudando));

for ( count = 0; count < N; count++)
{
printf("\n===============================================\n");
printf("qual o nome do aluno\n");
scanf(" %254[^\n]s",aluno->nome);
printf("qual o numero da matricula do aluno\n");
scanf("%d",&aluno->matricula);
scanf("%d",&aluno->periodo);
printf("qual a turma do aluno\n");
scanf("%d",&aluno->turma);
printf("qual o curso do aluno\n");
scanf(" %99[^\n]s",aluno->curso);
printf("=================================================\n");
}

system("cls");

for ( count = 0; count < N; count++)
{printf("\n=========================================================================================================\n");
    printf("\t\t o nome do aluno e : %s\n",aluno->nome);      
    printf("\t\t sua matricula e : %d\n",aluno->matricula);   
    printf("\t\t o periodo e : %d\n",aluno->periodo);         
    printf("\t\t esta na turma %d\n",aluno->turma);           
    printf("\t\t faz o curso de %s\n",aluno->curso);          
printf("=========================================================================================================\n");
}
free(aluno);
    return(0);
}
