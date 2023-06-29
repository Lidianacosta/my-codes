#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VAGAS 3
#define MAX_TURMAS 2
#define QTD_NOTAS 3
typedef struct aluno {
 int mat;
 char nome[81];
 float notas[QTD_NOTAS];
 float media;
}Aluno;
typedef struct turma {
 char id; /* caractere que identifica a turma, por exemplo, A ou B */
 int vagas; /* números de vagas disponíveis para fechar a turma */
 Aluno* alunos[MAX_VAGAS];
}Turma;

Turma* cria_turma(char id);
void matricula_aluno(Turma* turma, int mat, char* nome);
void imprime_alunos(Turma* turma);
void lanca_notas(Turma* turma);
void imprime_turmas(Turma** turmas, int n);
Turma* procura_turma(Turma** turmas, int n, char id);


Turma* cria_turma(char id){
int cont_alunos;
Turma *nova_turma = (Turma*)malloc(sizeof(Turma));
printf("Criando nova turma...");
nova_turma->vagas = MAX_VAGAS;
nova_turma->id = id;

for(cont_alunos = 0; cont_alunos<MAX_VAGAS;cont_alunos++){
    nova_turma->alunos[cont_alunos] = NULL;
}
printf("Turma %c criada com sucesso!",nova_turma->id);
    return(nova_turma);
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    int cont_alunos,cont_notas;

    for(cont_alunos=0;cont_alunos<MAX_VAGAS;cont_alunos++){
        if(turma->alunos[cont_alunos] == NULL){
            turma->alunos[cont_alunos]->mat = mat;
            strcpy(turma->alunos[cont_alunos]->nome,nome);
            for(cont_notas=0;cont_notas<QTD_NOTAS;cont_notas++){
            turma->alunos[cont_alunos]->notas[cont_notas] = 0;
            }
            turma->alunos[cont_alunos]->media = 0;
            break;
        }
    }
    printf("Aluno cadastrado com sucesso!\n");
    turma->vagas -= 1;
}

void imprime_alunos(Turma* turma){
    int cont_alunos,cont_se_tem_alunos_cadastrados=0;
    
    for(cont_alunos =0; cont_alunos<MAX_VAGAS;cont_alunos++){
        if(turma->alunos[cont_alunos] != NULL){
            printf("matricula: %d \nAluno: %s\nMedia: %f\n",turma->alunos[cont_alunos]->mat,turma->alunos[cont_alunos]->nome,turma->alunos[cont_alunos]->media);
            cont_se_tem_alunos_cadastrados++;
        }
    }

    if (cont_se_tem_alunos_cadastrados == 0);{
       printf("nenhum aluno cadastrado!\n");
    }
}

void lanca_notas(Turma* turma){
    int cont_alunos,cont_notas,cont_se_tem_alunos_cadastrados=0;
    float soma_notas=0;
    printf("Lancando notas...");
    for(cont_alunos =0; cont_alunos<MAX_VAGAS;cont_alunos++){
        soma_notas = 0;
        if(turma->alunos[cont_alunos] != NULL){
            printf("matricula: %d \tAluno: %s\n",turma->alunos[cont_alunos]->mat,turma->alunos[cont_alunos]->nome);            
            for(cont_notas=0;cont_notas<QTD_NOTAS;cont_notas++){
                printf("digite a nota %d: ",cont_notas+1);
                scanf("%f",turma->alunos[cont_alunos]->notas[cont_notas]);
                soma_notas+=turma->alunos[cont_alunos]->notas[cont_notas];
            }
           turma->alunos[cont_alunos]->media = soma_notas/QTD_NOTAS;
           cont_se_tem_alunos_cadastrados++;
        }

    }

    if (cont_se_tem_alunos_cadastrados == 0);{
       printf("nenhum aluno cadastrado!\n");
    }
}

void imprime_turmas(Turma** turmas, int n){
    int cont_turmas;
    printf("Listando turmas...");
    for(cont_turmas=0;cont_turmas<n;cont_turmas++){
        printf("Turma %c - %d vagas disponiveis\n",turmas[cont_turmas]->id,turmas[cont_turmas]->vagas);
    }
}

 Turma* procura_turma(Turma** turmas, int n, char id){
     int cont_turmas;
     for(cont_turmas=0;cont_turmas<n;cont_turmas++){
         if(turmas[cont_turmas]->id == id){
             return(turmas[cont_turmas]);
         }
     }
 }
