#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

double convet_pes_m(double pes){
    double m = pes/3.281;
    return m;
}

int main(){
    double pes;
    printf("\nDIGITE O VALOR EM PES: ");
    scanf("%lf", &pes);

    double m = convet_pes_m(pes);

    printf("\nCM = %.4f", m);

    return 0;
}