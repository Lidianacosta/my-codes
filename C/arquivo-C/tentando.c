// progama para escrever me um arquivo.

#include<stdio.h>
#include<stdlib.h>

#define qtd_aluno 3

typedef struct aluno{
    char nome[50];
    char mat[10];
    char curso[50];
}Aluno;

int main(void){
    int i;

    Aluno **aluno = (Aluno**)malloc(qtd_aluno*sizeof(Aluno*));

    if(aluno==NULL){
        printf("nao ha memoria suficiene\n");
        exit(1);
    }
    for(i=0;i<qtd_aluno;i++){
    aluno[i] = (Aluno*)malloc(sizeof(Aluno));
    }

    FILE* fp;

    fp = fopen("./tentando.doc", "w");
    
    if(fp == NULL){
        printf("nao foi posisvel abrir o arquivo\n");
        return(1);
    }

    for(i=0;i<qtd_aluno;i++){
    printf("digite os dados do aluno:\n");
    printf("nome: ");
    scanf(" %[^\n]s",aluno[i]->nome);
    printf("matricula: ");
    scanf(" %[^\n]s",aluno[i]->mat);
    printf("curso: ");
    scanf(" %[^\n]s",aluno[i]->curso);
    printf("\n");
    fprintf(fp, "%s\n",aluno[i]->nome);
    fprintf(fp, "%s\n",aluno[i]->mat);
    fprintf(fp, "%s\n\n",aluno[i]->curso);
    }
    
    for(i=0;i<qtd_aluno;i++){
    free(aluno[i]);
    }
    free(aluno);
    
    fclose(fp);
    return(0);
}
==========================================================================================================================
// progama para ler de um arquivo.
  
#include<stdio.h>
#include<stdlib.h>

#define qtd_aluno 3

typedef struct aluno{
    char nome[50];
    char mat[10];
    char curso[50];
}Aluno;


int main(void){
    int i;

    Aluno **aluno = (Aluno**)malloc(qtd_aluno*sizeof(Aluno*));

    if(aluno==NULL){
        printf("nao ha memoria suficiene\n");
        exit(1);
    }
    for(i=0;i<qtd_aluno;i++){
    aluno[i] = (Aluno*)malloc(sizeof(Aluno));
    
        if(aluno[i]==NULL){
            printf("nao ha memoria suficiene\n");
            exit(1);
        }
    }

    FILE* fp;

    fp = fopen("./tentando.doc", "r");
    
    if(fp == NULL){
        printf("nao foi posisvel abrir o arquivo\n");
        return(1);
    }

    for(i=0;i<qtd_aluno;i++){
   

    fscanf(fp, " %[^\n]s",aluno[i]->nome);
    fscanf(fp, " %[^\n]s",aluno[i]->mat);
    fscanf(fp, " %[^\n]s",aluno[i]->curso);

    printf("%s\n",aluno[i]->nome);
    printf("%s\n",aluno[i]->mat);
    printf("%s\n\n",aluno[i]->curso);
    }
    
    for(i=0;i<qtd_aluno;i++){
    free(aluno[i]);
    }
    free(aluno);
    
    fclose(fp);
    return(0);
}
=========================================================================================================================
//dados de pessoas so pra testar
  
lidiana costa 
01
tecnologia da informacao

mateus victor 
02
tecnologia da informacao

lucas mairon
03
tecnologia da informacao
