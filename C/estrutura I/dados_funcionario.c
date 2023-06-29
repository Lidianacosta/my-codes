#include<stdio.h>
#include<stdlib.h>

typedef struct dados_funcionario{
    char nome_fucionario[50];
    float salario;
    char cargo[50];
}Dados_funcionario;

void cadastra(int n, Dados_funcionario *f);
void mostra(int n ,Dados_funcionario *f);

int main(void){
    int n,count;
    printf("digite o numero de funcionarios que deseja cadastra: ");
    scanf("%d",&n);

    Dados_funcionario *funcionarios = (Dados_funcionario*)malloc(n * sizeof(Dados_funcionario));

    cadastra(n,funcionarios);
    mostra(n,funcionarios);
    
    free(funcionarios);
    return(0);
}

 void cadastra(int n, Dados_funcionario *f){
     int count;
     for(count = 0 ; count < n ; count++){
        printf("digite o nome do funcionario\n");
        scanf(" %[^\n]s",f[count].nome_fucionario);
        printf("digite o quanto o funcionario recebe\n");
        scanf("%f",&f[count].salario);
        printf("digite o qual o cargo do funcionario\n");
        scanf(" %[^\n]s",f[count].cargo);
     }
 }

void mostra(int n ,Dados_funcionario *f){
    int count;
    for(count = 0 ; count < n ; count++){
        printf("%s\n",f[count].nome_fucionario);
        printf("%f\n",f[count].salario);
        printf("%s\n",f[count].cargo);
    }
 }
