#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_aluno{ //Define o struct tipo_aluno
    char nome [50];
    int nota1;
    int nota2;
    float media;
} tipo_aluno;

void limpar_tela(){ //Limpa o terminal (identifica se o usuário usa macOS, Linux ou Windows)
    #ifdef _WIN32
        system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
        system("clear");
    #else
        printf("\n");
    #endif
}

int verificar_nome(tipo_aluno *lista, int qtd, char *nome){ //Verifica se o nome já existe na lista de alunos
    for(int i = 0; i < qtd; i++){
        if(strcmp(nome, lista[i].nome) == 0 ){
            return 0;
        }
    }

    return 1;
}

void inserir_aluno(tipo_aluno *lista_de_alunos, int *alunos_na_turma){ //Insere o aluno na lista, chama a função verificar_nome e também adiciona a média
    char nome[50];
    int nota1, nota2;
    float media;
    int valido = 0;

    limpar_tela();
    printf("\n");
    printf("\nEsse é o %dº aluno na turma.\n", *alunos_na_turma + 1);

    do{
        printf("\nDigite o nome do aluno: ");
        scanf(" %49[^\n]", nome);

        if(verificar_nome(lista_de_alunos, *alunos_na_turma, nome) == 0){
            limpar_tela();
            printf("\nERRO! Já existe esse nome!\n");
        } else {
            valido = 1;
        }

    }while(valido == 0);

    strcpy(lista_de_alunos[*alunos_na_turma].nome, nome); //Faz a cópia do char

    printf("\nDigite a 1ª nota do aluno: ");
    scanf(" %d", &nota1);

    printf("\nDigite a 2ª nota do aluno: ");
    scanf(" %d", &nota2);

    lista_de_alunos[*alunos_na_turma].nota1 = nota1;
    lista_de_alunos[*alunos_na_turma].nota2 = nota2;
    
    media = (nota1 * 3.0 + nota2 * 7.0) / 10.0;

    lista_de_alunos[*alunos_na_turma].media = media;

    (*alunos_na_turma)++;

    limpar_tela();

    printf("\nAluno inserido com sucesso!\n");

}

void exibir_alunos(tipo_aluno *lista_de_alunos, int alunos_na_turma){ //Exibi a lista de alunos com o seu número
    limpar_tela();    
    printf("\n============ ALUNOS ============\n");

    for(int i = 0; i < alunos_na_turma; i++){
        printf("\n%d - %s", i + 1, lista_de_alunos[i].nome);
    }
}

void exibir_informacoes(tipo_aluno *lista_de_aluno, int num_aluno){ //Exibi as informações do aluno (Nome, nota1, nota2 e média)
    limpar_tela();
    printf("\n============= NOTAS =============\n");
    printf("\nNome: %s\n", lista_de_aluno[num_aluno - 1].nome);
    printf("1ª Nota: %d\n", lista_de_aluno[num_aluno - 1].nota1);
    printf("2ª Nota: %d\n", lista_de_aluno[num_aluno - 1].nota2);
    printf("Media: %.2f\n", lista_de_aluno[num_aluno - 1].media);
}

void alterar_notas(tipo_aluno *lista_de_alunos, int num_aluno){ //Altera as notas do aluno e a média
    int nota1, nota2;
    float media;

    printf("\n========= ALTERAR NOTAS ==========\n");
    printf("\nDigite a 1ª Nota: ");
    scanf(" %d", &nota1);

    printf("\nDigite a 2ª Nota: ");
    scanf(" %d", &nota2);

    media = (nota1 * 3.0 + nota2 * 7.0) / 10.0;

    lista_de_alunos[num_aluno - 1].nota1 = nota1;
    lista_de_alunos[num_aluno - 1].nota2 = nota2;
    lista_de_alunos[num_aluno - 1].media = media;

    limpar_tela();

    printf("\nNotas alteradas com sucesso!\n");  
}

float media_turma(tipo_aluno *lista_de_alunos, int alunos_na_turma){ //Calcula a média da turma, somando todas médias e dividindo pelos alunos
    float soma = 0;

    for(int i = 0; i < alunos_na_turma; i++){
        soma+= lista_de_alunos[i].media;
    }

    soma /= alunos_na_turma;

    return soma;
}


int main(){
    tipo_aluno *lista_de_alunos = NULL;
    int alunos_na_turma = 0;
    int capacidade = 0;

    int opcao_menu = 0;

    int num_aluno = 0;

    do{
        printf("\n============= MENU =============\n");
        printf("\n1 - Inserir Aluno\n");
        printf("2 - Consultar notas de um aluno\n");
        printf("3 - Alterar notas de um aluno\n");
        printf("4 - Consultar media da turma\n");
        printf("0 - Encerrar Sistema\n");
        printf("\nEscolha uma opcao: ");

        scanf(" %d", &opcao_menu);

        switch(opcao_menu){
            case 1:
                if(alunos_na_turma == capacidade){
                    capacidade+= 5;
                    lista_de_alunos = (tipo_aluno *) realloc(lista_de_alunos, capacidade * sizeof(tipo_aluno));
                }
                inserir_aluno(lista_de_alunos, &alunos_na_turma);

            break;

            case 2:

                if(alunos_na_turma != 0){
                    exibir_alunos(lista_de_alunos, alunos_na_turma);

                    do{
                        printf("\n\n0 - Sair\n");

                        printf("\nEscolha uma opcao: ");
                        scanf(" %d", &num_aluno);

                    if(num_aluno == 0){
                        limpar_tela();

                    } else if(num_aluno > alunos_na_turma || num_aluno < 0){
                        printf("\nERRO! Numero Invalido!");

                    } else {
                        exibir_informacoes(lista_de_alunos, num_aluno);
                        num_aluno = 0;
                    }

                }while(num_aluno != 0);

                } else {
                    limpar_tela();
                    printf("\nERRO! Nao existe nenhum aluno cadastrado!\n");
                }

                break;

            case 3:

                if(alunos_na_turma != 0){
                    exibir_alunos(lista_de_alunos, alunos_na_turma);

                    do{
                        printf("\n\n0 - Sair\n");

                        printf("\nEscolha uma opcao: ");
                        scanf(" %d", &num_aluno);

                    if(num_aluno == 0){
                        limpar_tela();

                    } else if(num_aluno > alunos_na_turma || num_aluno < 0){
                        limpar_tela();
                        printf("\nERRO! Numero Invalido!");

                    } else {
                        exibir_informacoes(lista_de_alunos, num_aluno);
                        alterar_notas(lista_de_alunos, num_aluno);
                        num_aluno = 0;
                    }

                }while(num_aluno != 0);

                } else {
                    limpar_tela();
                    printf("\nERRO! Nao existe nenhum aluno cadastrado!\n");
                }

                break;

            case 4:

                if(alunos_na_turma != 0){
                    limpar_tela();
                    printf("\n======== MEDIA DA TURMA ========\n");
                    printf("\nMedia: %.2f\n", media_turma(lista_de_alunos, alunos_na_turma));

                } else {
                    limpar_tela();
                    printf("\nERRO! Nao existe nenhum aluno cadastrado!\n");
                }
            
            break;

            case 0:
            limpar_tela();
            printf("\nEncerrando...\n");
            break;

            default:

            printf("\nERRO! Opcao Invalida, Tente Novamente!\n");

            break;
        }

    }while(opcao_menu != 0);

    free(lista_de_alunos);

    return 0;
}