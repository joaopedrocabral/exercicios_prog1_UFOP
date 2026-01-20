#include <stdio.h>
#include <stdlib.h>

#define QTD 2

#define RED   "\033[31m"
#define RESET "\033[0m"



void preencher_matriz(int matriz[QTD][4]){

    for(int i = 0; i < QTD; i++){

        system("clear");

        printf("\n---------------------------\n");
        
        printf("\nDIGITE AS INFORMACOES PARA O " RED "%dº" RESET " ALUNO: \n", i+1);

        printf("\nDigite a " RED "matricula: " RESET);
        scanf(" %d", &matriz[i][0]);

        printf("\nDigite o " RED "sexo" RESET " (1 - masc / 0 - fem): ");
        scanf(" %d", &matriz[i][1]);

        matriz[i][2] = (matriz[i][0] / 1000) % 1000;

        printf("\nDigite o " RED "coeficiente de rendimento" RESET " (0-10): ");
        scanf(" %d", &matriz[i][3]);
    }

    system("clear");
}

void exibir_matriz_completa(int matriz[QTD][4]){
    for(int i = 0; i < QTD; i++){
        
        printf("\n---------------------------\n");
        printf("\nINFORMACOES DO " RED "%dº" RESET " ALUNO: \n", i+1);

        printf("\nMatricula: %d", matriz[i][0]);

        if(matriz[i][1] == 0){
            printf("\nSexo: Feminino");
        } else {
            printf("\nSexo: Masculino");
        }

        printf("\nCódigo do Curso: %d", matriz[i][2]);
        printf("\nCoeficiente de Rendimento: %d\n", matriz[i][3]);
        
    }
}

int calcular_maior_cr_curso(int matriz[QTD][4], int sexo, int codigo_curso){

    int maior_cr = 0;
    int matricula = 0;

    for(int i = 0; i < QTD; i++){
        if(matriz[i][1] == sexo && matriz[i][2] == codigo_curso){
            if(matriz[i][3] > maior_cr){
                maior_cr = matriz[i][3];
                matricula = matriz[i][0];
            }
        }
    }

    if(matricula != 0){
        return matricula;
    }

    return 0;
    
}

void exibir_sexo(int sexo){
    if(sexo == 0){
        printf("\nSexo: Feminino");
    } else {
        printf("\nSexo: Masculino");
    }
}

void exibir_informacoes_maior_cr(int matriz[QTD][4], int matricula){
    for(int i = 0; i < QTD; i++){
        if(matriz[i][0] == matricula){
            system("clear");
            
            printf("\n---------------------------\n");

            printf("\nINFORMACOES DO MAIOR CR: \n");

            printf("\nMatricula: %d", matriz[i][0]);

            exibir_sexo(matriz[i][1]);

            printf("\nCódigo do Curso: %d", matriz[i][2]);
            printf("\nCoeficiente de Rendimento: %d\n", matriz[i][3]);

        }
    }
}

int main(){
    int matriz[QTD][4];
    int opcao = 0;
    int matriz_preenchida = 0;

    do{
        printf("\n=====MENU=====\n");
        printf("\n1 - Preencher Cadastro dos Alunos\n");
        printf("2 - Exibir todos os Cadastros\n");
        printf("3 - Calcular e Exibir maior CR\n");
        printf("0 - Sair\n");

        printf("\nDigite uma opcao: ");
        scanf(" %d", &opcao);


        switch(opcao){
            
            case 1:
                preencher_matriz(matriz);
                matriz_preenchida = 1;
            break;

            case 2:
                if(matriz_preenchida != 0){
                    exibir_matriz_completa(matriz);
                } else {
                    system("clear");
                    printf(RED "\nERRO! Matriz nao preenchida!" RESET);
                }
            break;

            case 3:
                if(matriz_preenchida != 0){
                    int codigo_curso, sexo;

                    printf("\nQual o codigo do curso: ");
                    scanf(" %d", &codigo_curso);

                    printf("\nQual o sexo (1 - masc / 0 - fem): ");
                    scanf(" %d", &sexo);

                    int matricula = calcular_maior_cr_curso(matriz, sexo, codigo_curso);

                    if(matricula != 0){
                        exibir_informacoes_maior_cr(matriz, matricula);
                    } else {
                        printf(RED "\nERRRO! Nenhum aluno desse sexo encontrado para esse curso!" RESET);
                    }

                } else {
                    system("clear");
                    printf(RED "\nERRO! Matriz nao preenchida!" RESET);
                }

            break;

            case 0:
            printf("\nSaindo...\n");
            break;

            default:
                printf(RED "\nERRO! Opcao Invalida!\n" RESET);
            break;
        }


    }while(opcao!=0);

    return 0;


}