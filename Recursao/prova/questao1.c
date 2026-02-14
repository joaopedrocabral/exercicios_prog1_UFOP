#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    float salario;
} funcionarios;

void preencher_lista(funcionarios *lista, int *qtd_funcionarios){
    for(int i = 0; i < *qtd_funcionarios; i++){
        printf("\nDigite o nome do funcionário: ");
        scanf(" %49[^\n]", *(lista + i)->nome);

        printf("\nDigite a idade do funcionario: ");
        scanf(" %d", (lista + i)->idade);

        printf("\nDigite o sálario: R$");
        scanf(" %f", (lista + i)->salario);

        (*qtd_funcionarios)++;

        printf("\nFuncionario registrado com sucesso!");
    }
}

int maior_salario(funcionarios *lista, int qtd_funcionarios){
    float maior = lista->salario;
    int posicao = 0;

    for(int i = 1; i < qtd_funcionarios; i++){
        if(lista[i].salario > maior){
            maior = lista[i].salario;
            posicao = i;
        }
    }

    return posicao;
}

void exibir(funcionarios *lista, int indice){
    printf("\nINFORMAÇÕES:\n");
    printf("\nNome: %s", lista[indice].nome);
    printf("Idade: %d", lista[indice].idade);
    printf()
}

int main(){
    funcionarios *lista;
    int qtd_funcionarios;

    printf("\nDigite a quantidade de funcionários: ");
    scanf(" %d", &qtd_funcionarios);

    lista = malloc(qtd_funcionarios * sizeof(funcionarios));

    if(lista == NULL){
        printf("\nErro de alocação de memória!\n");
        return 0;
    }


}