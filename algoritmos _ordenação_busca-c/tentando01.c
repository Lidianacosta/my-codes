#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void selecao(int* vet ,int tam);

int busca_interpolada(int *vet ,int tam, int idx);

int main(void){
    int i,index,idx,tam;
    int vetor[TAM];

    char linha[100];
    
    FILE* entrada = fopen("entradabusca.txt", "r");
    if (entrada == NULL){
        printf("erro ao abrir o arquivo de entrada!\n");
        return(1);
    }
    
    FILE* saida = fopen("saidabusca.txt", "wt");
    if(saida == NULL){
       printf("erro ao abrir o arquivo de saida!\n");
       return(1);
    }
    
    while(fgets(linha,100,entrada)!= NULL){
        sscanf(linha, "%d",&vetor[i]);
        i++;

    }

    idx = 9;
    tam = sizeof(vetor)/sizeof(vetor[0]);
    
    selecao(vetor,TAM);
    index = busca_interpolada(vetor,tam,idx);

    if(index != -1){
        printf("elemento encontrado no index %d\n", index);
    }else{
        printf("elemento nao encontrado no vetor!\n");
    }

   for (i = 0; i < TAM; i++){
        fprintf(saida, "v[%d] = %d\n",i,vetor[i]);
    }

    fclose(entrada);
    fclose(saida);
    return(0);
}
void selecao(int* vet ,int tam){
    int i,j,min,x;
    for(i = 0 ; i < tam-1 ; i++){
        min = i;
        for (j = i+1; j < tam ; j++){
            if (vet[j] < vet[min]){
                min = j;
            }
        }
        x = vet[min];
        vet[min] = vet[i];
        vet[i] = x ;
    }
    printf("=============================================================\n");
    for (i = 0; i < TAM; i++){
        printf("v[%d] = %d\n",i,vet[i]);
    }
    printf("ordenado com Selection Sort!");

}
int busca_interpolada(int *vet ,int tam, int idx){
    if(tam == 0){
        return(-1);
    }
    int menor = 0, maior = tam - 1, meio;

    while(vet[maior] != vet[menor] && idx >= vet[menor] && idx<=vet[maior]){
        meio = menor + ((idx - vet[menor]) * (maior - menor)/(vet[maior] - vet[menor]));
    if(idx == vet[meio]){
        return(meio);
    }
    else if (idx <vet[meio]){
        maior = meio -1;
    }else{
        menor = meio +1;
    }
    }

    if(idx == vet[menor]){
        return(menor);
    }else{
        return(-1);
    }

}
