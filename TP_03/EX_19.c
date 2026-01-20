#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(double a, double b, double c, double *x1, double *x2){
    double delta = pow(b,2) - 4 * a * c;
    
    if(delta < 0) return -1;
    double raiz_delta = sqrt(delta);
    if(fabs(raiz_delta - round(raiz_delta)) > 1e-9) return -1;

    *x1 = (-b + raiz_delta)/(2*a);
    *x2 = (-b - raiz_delta)/(2*a);

    if(delta == 0) return 1;
    if(delta != 0) return 2;

    return -1;
}

int main(){
    double a, b, c, x1, x2;

    printf("\nDIGITE OS COEFICIENTES DA EQUACAO (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    switch(raizes(a, b, c, &x1, &x2)){
        case -1:
        printf("\nNAO E POSSIVEL CALCULAR AS RAIZES DESSA EQUACAO!");
        break;

        case 1:
        printf("\nA EQUACAO POSSUI APENAS UMA RAIZ: X1 = %.1f", x1);
        break;

        case 2:
        printf("\nA EQUACAO POSSUI DUAS RAIZES: X1 = %.1f E X2 = %.1f", x1, x2);
        break;
    }

    return 0;
}