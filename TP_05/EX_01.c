#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTATOS 100
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

typedef struct{
    int ddd;
    char numero[12];
} telefone;

typedef struct{
    int dia;
    int mes;
    int ano;
} data;

typedef struct{
    char rua[100];
    char numero [10];
    char complemento[50];
    char bairro[50];
    char cep[10];
    char cidade[50];
    char estado[30];
    char pais[30];
} endereco;

typedef struct{
    int codigo;
    char nome[100];
    char email[100];

    endereco endereco;
    telefone telefone;
    data aniversario;

    char obs[200];

} contato;

void limpar_tela(){
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__) || defined (__APPLE__)
        system("clear");
    #else
        printf("\n");
    #endif
}

void preencher_dados_pessoais(contato *agenda, int codigo){

    printf("\nDigite o nome do Contato: ");
    scanf(" %99[^\n]", agenda[codigo].nome);

    printf("\nDigite o e-mail desse Contato: ");
    scanf(" %99[^\n]", agenda[codigo].email);

}

void preencher_endereco(contato *agenda, int codigo){

    limpar_tela();
    printf("ENDEREÇO:\n");

    printf("\nRua: ");
    scanf(" %99[^\n]", agenda[codigo].endereco.rua);

    printf("\nNúmero (S/N se não houver): ");
    scanf(" %9[^\n]", agenda[codigo].endereco.numero);

    printf("\nComplemento (S/C se não houver): ");
    scanf(" %49[^\n]", agenda[codigo].endereco.complemento);

    printf("\nBairro: ");
    scanf(" %49[^\n]", agenda[codigo].endereco.bairro);

    printf("\nCEP (00000-000): ");
    scanf(" %9[^\n]", agenda[codigo].endereco.cep);

    printf("\nCidade: ");
    scanf(" %49[^\n]", agenda[codigo].endereco.cidade);

    printf("\nEstado: ");
    scanf(" %29[^\n]", agenda[codigo].endereco.estado);

    printf("\nPaís: ");
    scanf(" %99[^\n]", agenda[codigo].endereco.pais);

}

void preencher_telefone(contato *agenda, int codigo){

    limpar_tela();
    printf("TELEFONE:\n");

    printf("\nDigite o DDD (00): ");
    scanf(" %d", &agenda[codigo].telefone.ddd);

    printf("\nDigite o Número (0 0000-0000): ");
    scanf(" %11[^\n]", agenda[codigo].telefone.numero);
}

void preencher_aniversario(contato *agenda, int codigo){

    int dia, mes, ano;

    limpar_tela();
    printf("DATA DE NASCIMENTO\n");

    do{
        printf("\nDigite o dia (1 a 31): ");
        scanf(" %d", &dia);

        if(dia < 1 || dia > 31){
            printf(RED"Dia inválido!"RESET" Tente novamente.\n");
        }

    }while(dia < 1 || dia > 31);

    do{
        printf("\nDigite o mês (1 a 12): ");
        scanf(" %d", &mes);

        if(mes < 1 || mes > 12){
            printf(RED"Mês inválido!"RESET" Tente novamente.\n");
        }

    }while(mes < 1 || mes > 12);

    do{
        printf("\nDigite o ano: ");
        scanf(" %d", &ano);

        if(ano <= 0){
            printf(RED"Ano inválido!"RESET" Tente novamente.\n");
        }

    }while(ano <= 0);

    agenda[codigo].aniversario.dia = dia;
    agenda[codigo].aniversario.mes = mes;
    agenda[codigo].aniversario.ano = ano;
}

void inserir_contato(contato *agenda, int *qtd_contatos){
    printf("\n========== NOVO CONTATO =========\n");
    printf("\nEsse é o "RED"%dº"RESET" contato!\n", *qtd_contatos + 1);

    agenda[*qtd_contatos].codigo = (*qtd_contatos) + 1;

    preencher_dados_pessoais(agenda, *qtd_contatos);

    preencher_endereco(agenda, *qtd_contatos);

    preencher_telefone(agenda, *qtd_contatos);

    preencher_aniversario(agenda, *qtd_contatos);

    limpar_tela();

    int opcao_obs;

    printf("\nEsse contato possui alguma observação?\n");
    printf("\n1 - Sim\n");
    printf("0 - Não\n");
    printf("\nEscolha uma opção: ");
    scanf(" %d", &opcao_obs);

    if(opcao_obs == 1){

        printf("\nDigite a observação: ");
        scanf(" %199[^\n]", agenda[*qtd_contatos].obs);

    } else if(opcao_obs == 0){

        agenda[*qtd_contatos].obs[0] = '\0';
    }

    (*qtd_contatos)++;

    limpar_tela();
    printf(GREEN"\nContato Registrado com Sucesso!\n"RESET);
    
}

void exibir_lista_nomes(contato *agenda, int qtd_contatos){
    printf("\n============= "RED"LISTA"RESET" ============\n");
    
    for(int i = 0; i < qtd_contatos; i++){
        printf("\n%d - %s", i + 1, agenda[i].nome);
    }
    printf("\n");
}

void exibir_inf_basica(contato *agenda, int cod_contato){
    
    printf("\n=========== "RED"%dº"RESET" CONTATO =========\n", cod_contato + 1);
    printf("\nCódigo: %d\n", agenda[cod_contato].codigo);

    printf("Nome: %s\n", agenda[cod_contato].nome);
    printf("E-mail: %s\n", agenda[cod_contato].email);
    printf("Telefone: (%d) %s\n", agenda[cod_contato].telefone.ddd, agenda[cod_contato].telefone.numero);
}

void exibir_inf_detalhada(contato *agenda, int cod_contato){

    printf("\n=========== "RED"%dº"RESET" CONTATO =========\n", cod_contato + 1);
    printf("\nCódigo: %d\n", agenda[cod_contato].codigo);

    printf("Nome: %s\n", agenda[cod_contato].nome);
    printf("E-mail: %s\n", agenda[cod_contato].email);

    printf("\nENDEREÇO:\n");
    printf("Rua: %s\n", agenda[cod_contato].endereco.rua);
    printf("Número: %s\n", agenda[cod_contato].endereco.numero);
    printf("Complemento: %s\n", agenda[cod_contato].endereco.complemento);
    printf("Bairro: %s\n", agenda[cod_contato].endereco.bairro);
    printf("CEP: %s\n", agenda[cod_contato].endereco.cep);
    printf("Cidade: %s\n", agenda[cod_contato].endereco.cidade);
    printf("Estado: %s\n", agenda[cod_contato].endereco.estado);
    printf("\nPaís: %s\n", agenda[cod_contato].endereco.pais);

    printf("\nTELEFONE:\n");
    printf("Número: (%d) %s\n", agenda[cod_contato].telefone.ddd, agenda[cod_contato].telefone.numero);

    printf("\nData de Nascimento: %d/%d/%d\n",
        agenda[cod_contato].aniversario.dia,
        agenda[cod_contato].aniversario.mes,
        agenda[cod_contato].aniversario.ano);

    if(strlen(agenda[cod_contato].obs) == 0){
        printf("\nObservações: (nenhuma)\n");

    } else {
        printf("\nObservações: %s\n", agenda[cod_contato].obs);
    }

}

void excluir_contato(contato *agenda, int *qtd_contatos, int cod_contato){
    int posicao = -1;

    for(int i = 0; i < *qtd_contatos; i++){
        if(agenda[i].codigo == cod_contato){
            posicao = i;
            break;
        }
    }

    if(posicao == -1){
        printf(RED"\nERRO!"RESET" Código do Contato Inválido!");
        return;
    }

    for(int i = posicao; i < *qtd_contatos - 1; i++){
        agenda[i] = agenda[i + 1];
    }

    for(int i = 0; i < *qtd_contatos; i++){
        agenda[i].codigo = i + 1;
    }

    (*qtd_contatos)--;

    limpar_tela();
    printf(GREEN"\nContato excluido com sucesso!\n"RESET);
}

void extrair_pri_nome(char *nome_completo, char *primeiro_nome){
    int i = 0;

    for(; nome_completo[i] != ' ' && nome_completo[i] != '\0'; i++){
        primeiro_nome[i] = nome_completo[i];
    }
    primeiro_nome[i] = '\0';
}

void buscar_pri_nome(contato *agenda, int qtd_contatos, char *nome_buscar){
    char pri_nome[20];
    int encontrado = 0;

    limpar_tela();

    for(int i = 0; i < qtd_contatos; i++){
        extrair_pri_nome(agenda[i].nome, pri_nome);

        if(strcmp(pri_nome, nome_buscar) == 0){

            exibir_inf_detalhada(agenda, i);

            encontrado = 1;
        }
    }

    if(!encontrado){
        printf(RED"ERRO!"RESET" Nenhum contato encontrado com esse nome!\n");
    }
}

void buscar_mes(contato *agenda, int qtd_contatos, int mes){
    int encontrado = 0;

    for(int i = 0; i < qtd_contatos; i++){
        if(agenda[i].aniversario.mes == mes){
            exibir_inf_detalhada(agenda, i);
            encontrado++;
        }
    }

    if(!encontrado){
        printf(RED"ERRO!"RESET" Nenhum contato encontrado com esse mês de aniversário!\n");
    }

}

void buscar_dia_mes(contato *agenda, int qtd_contatos, int dia, int mes){
    int encontrado = 0;

    for(int i = 0; i < qtd_contatos; i++){
        if(agenda[i].aniversario.dia == dia &&
            agenda[i].aniversario.mes == mes){

                exibir_inf_detalhada(agenda, i);
                encontrado++;
        }
    }

    if(!encontrado){
        printf(RED"ERRO!"RESET" Nenhum contato encontrado com esse dia e mês de aniversário!\n");
    }
}

int main(){
    contato agenda[MAX_CONTATOS];
    int qtd_contatos = 0;

    int opcao_menu = 0;

    do{
        printf("\n============= "RED"MENU"RESET" =============\n");
        printf("\n1 - Inserir Novo Contato\n");
        printf("2 - Excluir um Contato\n");
        printf("3 - Buscar pelo 1º Nome\n");
        printf("4 - Buscar pelo mês de Aniversário\n");
        printf("5 - Buscar pelo dia e mês de Aniversário\n");
        printf("6 - Mostrar Informações\n");
        printf("0 - Encerrar Sistema\n");
        printf("\nEscolha uma opcao: ");

        scanf(" %d", &opcao_menu);

        switch(opcao_menu){

            case 1:

                limpar_tela();

                if(qtd_contatos < MAX_CONTATOS){
                    inserir_contato(agenda, &qtd_contatos);

                } else {
                    printf(RED"ERRO!"RESET" Agenda Cheia!\n");
                }

            break;

            case 2:
            
                limpar_tela();

                if(qtd_contatos != 0){
                    int cod_contato;

                    exibir_lista_nomes(agenda, qtd_contatos);

                    printf("\nDigite o código do Contato: ");
                    scanf(" %d", &cod_contato);

                    excluir_contato(agenda, &qtd_contatos, cod_contato);

                } else {
                    printf(RED"\nERRO!"RESET" Não existe nenhum contato na lista\n");
                }

            break;

            case 3:
            
                limpar_tela();

                if(qtd_contatos != 0){
                    char nome_buscar[20];

                    printf("\nDigite o nome: ");
                    scanf(" %19[^\n]", nome_buscar);

                    buscar_pri_nome(agenda, qtd_contatos, nome_buscar);

                } else {
                    printf(RED"\nERRO!"RESET" Não existe nenhum contato na lista\n");
                }

            break;

            case 4:
            
                limpar_tela();

                if(qtd_contatos != 0){
                    int mes;

                    printf("\nDigite o mês: ");
                    scanf(" %d", &mes);

                    buscar_mes(agenda, qtd_contatos, mes);

                } else {
                    printf(RED"\nERRO!"RESET" Não existe nenhum contato na lista\n");
                }

            break;

            case 5:
            
                limpar_tela();

                if(qtd_contatos != 0){
                    int dia, mes;

                    printf("\nDigite o dia: ");
                    scanf(" %d", &dia);

                    printf("\nDigite o mês: ");
                    scanf(" %d", &mes);

                    buscar_dia_mes(agenda, qtd_contatos, dia, mes);

                } else {
                    printf(RED"\nERRO!"RESET" Não existe nenhum contato na lista\n");
                }

            break;

            case 6:

                limpar_tela();
            
                if(qtd_contatos != 0){
                    int cod_contato;

                    exibir_lista_nomes(agenda, qtd_contatos);

                   
                        printf("\nDigite o código do contato: ");
                        scanf(" %d", &cod_contato);

                        if(cod_contato > qtd_contatos){
                            printf(RED"ERRO!"RESET" Código Inválido");
                        } else {
                            int opcao;

                            limpar_tela();

                            do{
                            printf("\n========== "RED"INFORMAÇÕES"RESET" =========\n");
                            printf("\n1 - Básicas");
                            printf("\n2 - Detalhadas");
                            printf("\n0 - Sair\n");

                            printf("\nEscolha uma opção: ");
                            scanf(" %d", &opcao);

                            switch(opcao){
                                case 1:

                                    limpar_tela();
                                    exibir_inf_basica(agenda, cod_contato - 1);

                                break;

                                 case 2:

                                    limpar_tela();
                                    exibir_inf_detalhada(agenda, cod_contato - 1);
                                    
                                break;

                                case 0:

                                    limpar_tela();

                                break;

                                default:

                                    printf(RED"ERRO!"RESET" Opção Inválida");

                                break;
                            }

                        }while(opcao != 0);
                     }

                } else {
                    printf(RED"\nERRO!"RESET" Não existe nenhum contato na lista\n");
                }

            break;

            case 0:

                printf("\nEncerrando...");

            break;

            default:

                limpar_tela();
                printf(RED"\nERRO!"RESET" Opção Invalida\n");

            break;
            
        }

    }while(opcao_menu != 0);

    return 0;
}