#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define QTD_ALUNOS 1 // conts para a qtd de alunos 

// typedef union documento{
//     char cpf[20];             nao sei se vou usar
//     char rg[20];
// }Documento;

typedef struct aluno{   // struct e seus elemento 
    char nome[51];
    int mat;
    char documento[21];
   // Documento documento;      nao sei se vou usar
}Aluno;

int main(void){
    char linha[100];
    //Aluno *alunos = (Aluno*) malloc(QTD_ALUNOS*sizeof(Aluno));
    Aluno alunos;
    FILE* entrada = fopen("alunos.txt", "rt");
    if(entrada == NULL){
        printf("erro na na abertura do arquivo!\n");
        exit(1);
    }
    FILE* saida = fopen("dados.txt", "a");
    if(saida == NULL){
        printf("erro na na abertura do aarquivo!\n");
        exit(1);
    }
    /*while(fgets(linha, 100, entrada) != NULL){
        //sscanf(linha, "", alunos->nome, &alunos->mat, alunos->documento);
        sscanf(linha, "%[^\t]s\n", alunos->nome);
        sscanf(linha, "%d\n", &alunos->mat);
        sscanf(linha, "%s\n", alunos->documento);
     
        //sscanf(linha, "%50[^\t]\n %d\n %20[^\t]\n",alunos.nome, &alunos.mat, alunos.documento);
    }*/
    fscanf(entrada, "%[^\t]s %d %s",alunos.nome, &alunos.mat, alunos.documento);
    printf("%s %d %s",alunos.nome, alunos.mat, alunos.documento);
    fprintf(saida, "%s\n%d\n%s\n",alunos.nome, alunos.mat, alunos.documento);
    //fscanf(entrada, "%[^\t]s %d %s",alunos->nome, &alunos->mat, alunos->documento);
    //printf("%s\n%d\n%s\n",alunos->nome, alunos->mat, alunos->documento);
   // fprintf(saida, "%s\n%d\n%s\n",alunos->nome, alunos->mat, alunos->documento);
    fclose(entrada);
    fclose(saida);
    //free(alunos);
    return(0);
}
