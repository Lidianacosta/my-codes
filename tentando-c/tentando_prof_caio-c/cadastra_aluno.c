#include<stdio.h>
#include<stdlib.h>

#define MAX_NOTAS 3

typedef struct aluno{
    char nome[50];
    char matricula[20];
    float notas[MAX_NOTAS];
    float media;
    char situacao[20];
}Aluno;

void main(void){

    int qtd_alunos,i,cont;
    float soma;
    printf("digite a quantidade de alunos que deseja cadastrar: ");
    scanf("%d",&qtd_alunos);

    Aluno **alunos = (Aluno**)malloc(qtd_alunos*sizeof(Aluno*));
    if(alunos == NULL){
        printf("memoria insuficiente!");
        exit(1);
    }

    for(i=0;i<qtd_alunos;i++){
        alunos[i] = (Aluno*)malloc(sizeof(Aluno));
            if(alunos[i] == NULL){
             printf("memoria insuficiente!");
             exit(1);
            }
    }
    
    for(i=0;i<qtd_alunos;i++){
        printf("digite os dados do aluno:n° %d\n",i+1);
        printf("nome: ");
        scanf(" %[^\n]s",alunos[i]->nome);
        printf("matricula: ");
        scanf(" %[^\n]s",alunos[i]->matricula);
        printf("as %d notas: \n",MAX_NOTAS);
        for(cont = 0;cont <MAX_NOTAS;cont++){
            printf("nota n° %d : ",cont+1);
            scanf("%f",&alunos[i]->notas[cont]);
        }
        for(cont = 0;cont <MAX_NOTAS;cont++){
            printf("nota n° %d : ",cont+1);
            soma += alunos[i]->notas[cont];
        }

        alunos[i]->media = soma/MAX_NOTAS;
        if(alunos[i]->media >=6){
            *alunos[i]->situacao = "Aprovado!";
        }else{
            *alunos[i]->situacao = "Reprovado!";
        }
    }


}
