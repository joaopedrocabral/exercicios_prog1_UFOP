#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double converter_rad(double grad){
    double rad = grad*(M_PI/180);

    return rad;
}

int main(){
    double grad;

    printf("\nDIGITE UM VALOR PARA CONVERTER EM REDIANO: ");
    scanf("%lf", &grad);

    double rad = converter_rad(grad);

    printf("\nO VALOR CONVERTIDO EM RADIANOS E: rad = %.5f", rad);

    return 0;
}