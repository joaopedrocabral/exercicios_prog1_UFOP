#include <stdio.h>
#include <stdlib.h>

int alfabeto(char caractere){
    if(caractere >= 'A' && caractere <= 'Z'){
        return 1;
    } else if(caractere >= 'a' && caractere <= 'z'){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    char caractere;

    printf("\nDIGITE UM CARACTERE: ");
    scanf(" %c", &caractere);

    if(alfabeto(caractere) == 1){
        printf("\nO CARACTERE E UMA LETRA DO ALFABETO");
    } else {
        printf("\nO CARACTERE NAO E UMA LETRA DO ALFABETO");
    }

    return 0;
}