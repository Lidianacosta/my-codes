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
void menu(void);
void imprime_alunos_ARQUIVO(Turma* turma,FILE *file);

int main(void){
    int op,mat,cont_turma=0,libera_turmas,libera_alunos;
    char id,nome[50];
    
    Turma **turmas = (Turma**)malloc(MAX_TURMAS*sizeof(Turma*));
    if(turmas == NULL){
        printf("amarazenamento isuficiente!");
        exit(1);
    }
    Turma *turma_encontrada = (Turma*)malloc(sizeof(Turma));
//======================================================================================
    FILE* file = fopen("./sistema_matricular_alunos.doc","w");
//======================================================================================
       
    do{
        menu();
        printf("\nDigite sua opcao: ");
        scanf("%d",&op); 
        printf("\n");
        switch (op){
        case 1: 
            if(cont_turma != MAX_TURMAS){
                printf("Criando nova turma...\n");
                printf("Digite um id: ");
                scanf(" %c",&id);
                turmas[cont_turma] = cria_turma(id);   
            cont_turma++;  
            }else{
                printf("nao ha mais vagas para cria turma!\n");
            }
            break;
        case 2:
             imprime_turmas(turmas,cont_turma);
            break;
        case 3:
            printf("Matriculando aluno...\n");
            printf("Digite um id: ");
            scanf(" %c",&id);
            turma_encontrada = procura_turma(turmas,cont_turma,id);
            if(turma_encontrada == NULL){
                printf("turma nao encontrada!\n");
                break;
            }
            if(turma_encontrada->vagas!=0){
                printf("Digite a matricula: ");
                scanf("%d",&mat);
                printf("Digite o nome: ");
                scanf(" %[^\n]s",nome);
                matricula_aluno(turma_encontrada,mat,&nome);
            }else{
                 printf("nao ha mais vaga na turma!\n");
            }
            break;
        case 4:
            printf("Digite um id: ");
            scanf(" %c",&id);
            turma_encontrada = procura_turma(turmas,cont_turma,id);
            if(turma_encontrada == NULL){
                printf("turma nao encontrada!\n");
                break;
            }
            lanca_notas(turma_encontrada);
            break;
        case 5:
            printf("Digite um id: ");
            scanf(" %c",&id);
            turma_encontrada = procura_turma(turmas,cont_turma,id);
            if(turma_encontrada == NULL){
                printf("turma nao encontrada!\n");
                break;
            } 
            imprime_alunos(turma_encontrada);
            break;
        case 7:
        imprime_alunos_ARQUIVO(turmas,file);
        break;
        default:
            printf("opcao invalida!");
            break;
        }     
    }while(op != 6);

    printf("Obrigado por usar este programa!\n");

    for(libera_turmas=0;libera_turmas<MAX_TURMAS;libera_turmas++){
        for(libera_alunos=0;libera_alunos<MAX_VAGAS;libera_alunos){
        free(turmas[libera_turmas]->alunos[libera_alunos]);
        }
    }
    for(libera_turmas=0;libera_turmas<MAX_TURMAS;libera_turmas++){
        free(turmas[libera_turmas]);
    }
    free(turmas);
    fclose(file);
    return(0);
}

Turma* cria_turma(char id){
int cont_alunos;
Turma *nova_turma = (Turma*)malloc(sizeof(Turma));
nova_turma->vagas = MAX_VAGAS;
nova_turma->id = id;

for(cont_alunos = 0; cont_alunos<MAX_VAGAS;cont_alunos++){
    nova_turma->alunos[cont_alunos] = NULL;
}
printf("Turma %c criada com sucesso!\n",nova_turma->id);
    return(nova_turma);
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    int cont_alunos,cont_notas;

    Aluno *novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    
    strcpy(novo_aluno->nome,nome);
    novo_aluno->mat = mat;
    
    for(cont_notas=0;cont_notas<QTD_NOTAS;cont_notas++){
            novo_aluno->notas[cont_notas] = 0;
    }
    novo_aluno->media = 0;
    
    for(cont_alunos=0;cont_alunos<MAX_VAGAS;cont_alunos++){
        if(turma->alunos[cont_alunos] == NULL){
            turma->alunos[cont_alunos] = novo_aluno;
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

    if (cont_se_tem_alunos_cadastrados == 0){
     printf("nenhum aluno cadastrado!\n");
    }
}

void lanca_notas(Turma* turma){
    int cont_alunos,cont_notas,cont_se_tem_alunos_cadastrados=0;
    float soma_notas=0;
    printf("Lancando notas...\n");
    for(cont_alunos =0; cont_alunos<MAX_VAGAS;cont_alunos++){
        soma_notas = 0;
        if(turma->alunos[cont_alunos] != NULL){
            printf("matricula: %d \tAluno: %s\n",turma->alunos[cont_alunos]->mat,turma->alunos[cont_alunos]->nome);            
            for(cont_notas=0;cont_notas<QTD_NOTAS;cont_notas++){
                printf("digite a nota %d: ",cont_notas+1);
                scanf("%f",&turma->alunos[cont_alunos]->notas[cont_notas]);
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
    printf("Listando turmas...\n");
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
     return(NULL);
 }

void menu(void){
    printf("\nMENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n7 - colocar em arquivo \n");
}


void imprime_alunos_ARQUIVO(Turma* turma,FILE *file){
    int cont_alunos,cont_se_tem_alunos_cadastrados=0;
    
    for(cont_alunos =0; cont_alunos<MAX_VAGAS;cont_alunos++){
        if(turma->alunos[cont_alunos] != NULL){
            fprintf(file, "matricula: %d \nAluno: %s\nMedia: %f\n",turma->alunos[cont_alunos]->mat,turma->alunos[cont_alunos]->nome,turma->alunos[cont_alunos]->media);
            cont_se_tem_alunos_cadastrados++;
        }
    }

    if (cont_se_tem_alunos_cadastrados == 0){
     printf("nenhum aluno cadastrado!\n");
    }

    printf("arquivado com sucesso!");
}
