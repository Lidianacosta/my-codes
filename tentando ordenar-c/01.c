#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[50];
    int idade;
}Pessoa;

int compararIdade(const void *x, const void *y){
    int pri = ((Pessoa *)x)->idade;
    int seg = ((Pessoa *)y)->idade;
    return(pri -seg);
}

int compararNome(const void *a, const void *b){
    return(strcmp(((Pessoa *)a)->nome,((Pessoa *)b)->nome));
}

int main(void){
    //Pessoa* pessoa = (pessoa)mallo
    Pessoa pessoa[5];
    int i;
    int idades[]={9,7,8,5,2};
    char nomes[][20] =  {"Joao","Pedro","Ana","Maria","Teste"};

    printf("Pessoas sem ordem:\n");
    for (i = 0; i < 5; i++) {
        strcpy(pessoa[i].nome, nomes[i]);
        pessoa[i].idade = idades[i];
        printf("%s: %d\n", pessoa[i].nome, pessoa[i].idade);
    }

    qsort(pessoa, 5, sizeof(Pessoa), compararIdade);

    printf("Pessoas ordenadas por idade:\n");
    for (i = 0; i < 5; i++) {
     printf("%s: %d\n", pessoa[i].nome, pessoa[i].idade);
    }

    qsort(pessoa, 5, sizeof(Pessoa), compararNome);
    printf("Pessoas ordenadas por nome:\n");
    for (i = 0; i < 5; i++) {
     printf("%s: %d\n", pessoa[i].nome, pessoa[i].idade);
    }


    return(0);
}
