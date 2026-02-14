#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float preco;
} produto;

void cadastrar_produto(produto *lista, int *qtd_cadastrada){
    printf("\nDigite o nome do produto: ");
    scanf(" %49[^\n]", lista[*qtd_cadastrada].nome);

    printf("\nDigite o preço do produto: R$ ");
    scanf(" %f", &lista[*qtd_cadastrada].preco);

    (*qtd_cadastrada)++;
}

float maior(produto *lista, int qtd_cadastrada){
    float maior = lista->preco;

    for(int i = 1; i < qtd_cadastrada + 1; i++){
        if(lista[i].preco > maior){
            maior = lista[i].preco;
        }
    }

    return maior;
}

float media(produto *lista, int qtd_cadastrada){
    float media = 0.0;

    for(int i = 0; i < qtd_cadastrada; i++){
        media += lista[i].preco;
    }

    media = (media/(float)qtd_cadastrada);

    return media;
}

int main(){
    produto *lista;
    int capacidade = 3;
    int qtd_cadastrada = 0;
    int opcao;

    lista = malloc(capacidade * sizeof(int));

    if(lista == NULL){
        printf("\nErro de alocação!");
        return 1;
    }

    do{
        printf("\n1 - Cadastrar Novo Produto\n");
        printf("2 - Produto mais caro e média de preços\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opção: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:

                if(qtd_cadastrada == capacidade){
                    capacidade += 3;
                    lista = realloc(lista,capacidade * sizeof(produto));

                    if(lista == NULL){
                        printf("\nErro de alocação!");
                        return 1;
                    }
                }

                cadastrar_produto(lista, &qtd_cadastrada);

            break;

            case 2:

                if(qtd_cadastrada != 0){

                    printf("\nMaior Valor: R$ %.2f\n", maior(lista, qtd_cadastrada));
                    printf("Média: R$ %.2f\n", media(lista, qtd_cadastrada));

                } else {
                    printf("\nERRO! Não existe produto cadastrado!");
                }

            break;

            case 0:
                printf("\nSaindo..\n");
            break;

            default:
                printf("\nOpcão Inválida, tente novamente!\n");
            break;
        }
    }while(opcao != 0);

    free(lista);
    return 0;
}