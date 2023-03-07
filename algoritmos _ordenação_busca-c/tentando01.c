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

	#include <stdio.h>
2	
3	#define TAM 10
4	
5	void selecao(int* vet ,int tam);
6	int busca_interpolada(int *vet ,int tam, int idx);
7	
8	int main(void){
9	    int i,index,idx,tam;
10	    int vetor[TAM] = {8,6,4,7,9,1,3,5,0,2};
11	    idx = 9;
12	    tam = sizeof(vetor)/sizeof(vetor[0]);
13	    selecao(vetor,TAM);
14	   
15	    index = busca_interpolada(vetor,tam,idx);
16	
17	    if(index != -1){
18	        printf("elemento encontrado no index %d", index);
19	    }else{
20	        printf("elemento nao encontrado no vetor!");
21	    }
22	    
23	    return(0);
24	}
25	void selecao(int* vet ,int tam){
26	    int i,j,min,x;
27	    for(i = 0 ; i < tam-1 ; i++){
28	        min = i;
29	        for (j = i+1; j < tam ; j++){
30	            if (vet[j] < vet[min]){
31	                min = j;
32	            }
33	        }
34	        x = vet[min];
35	        vet[min] = vet[i];
36	        vet[i] = x ;
37	    }
38	
39	    for (i = 0; i < TAM; i++){
40	        printf("v[%d] = %d\n",i,vet[i]);
41	    }
42	    printf("ordenado com Selection Sort!");
43	}
44	int busca_interpolada(int *vet ,int tam, int idx){
45	    if(tam == 0){
46	        return(-1);
47	    }
48	    int menor = 0, maior = tam - 1, meio;
49	
50	    while(vet[maior] != vet[menor] && idx >= vet[menor] && idx<=vet[maior]){
51	        meio = menor + ((idx - vet[menor]) * (maior - menor)/(vet[maior] - vet[menor]));
52	    if(idx == vet[meio]){
53	        return(meio);
54	    }
55	    else if (idx <vet[meio]){
56	        maior = meio -1;
57	    }else{
58	        menor = meio +1;
59	    }
60	    }
61	
62	    if(idx == vet[menor]){
63	        return(menor);
64	    }else{
65	        return(-1);
66	    }
67	
68	}
