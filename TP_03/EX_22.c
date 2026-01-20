#include <stdio.h>
#include <stdlib.h>

double convet_pol_cm(double pol){
    double cm = pol*2.54;
    return cm;
}

int main(){
    double pol;
    printf("\nDIGITE O VALOR EM POLEGADAS: ");
    scanf("%lf", &pol);

    double cm = convet_pol_cm(pol);

    printf("\nCM = %.2f", cm);

    return 0;
}