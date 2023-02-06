#include<stdio.h>
#include<stdlib.h>

void pedir_o_mapa(int m,int n, char **matriz){

int linha ,coluna;
printf("mostre como e seu mapa digite '.' para mar e '#'para terra\n");
for(linha = 0; linha<m ;linha++){

scanf(" %[^\n]s",matriz[linha]);

}

printf("sua matriz ta aqui\n");
for(linha = 0; linha<m ;linha++){

printf("%s\n",matriz[linha]);


}
}


void verifica_costa(int m ,int n,char **matriz){

int linha ,coluna,soma_costas = 0;

for(linha = 0;linha<m;linha++){
    for(coluna = 0;coluna<n;coluna++){

        if(matriz[linha][coluna] == '#'){

            if (matriz[linha][coluna +1] == '.' || matriz[linha][coluna -1] == '.' || matriz[linha + 1][coluna] == '.' || matriz[linha - 1][coluna] == '.'){

                soma_costas++;
            }
        }       
    }
}


printf("a quantidade de costas e : ");
printf(" %d",soma_costas);

}

int main(void)
{

//============================================
    int m,n,cont;
    printf("digite o numero de linhas e colunas\n");
   
    scanf("%d %d",&m,&n);
//============================================
    char **mapa = (char**)malloc(m*sizeof(char*));

    if(mapa == NULL) {
        printf("erro");
        exit(1);
    }

    for(cont = 0; cont < m; cont++) {

        mapa[cont] = (char*)malloc(n*sizeof(char));
          
          if(mapa[cont] == NULL) {
        printf("erro");
        exit(1);
    }
    }
//============================================

    pedir_o_mapa(m,n,mapa);
    verifica_costa(m,n,mapa);

//============================================
    for(cont = 0; cont < m; cont++) {
        free(mapa[cont]);
    }

 free(mapa);

    return(0);
}
