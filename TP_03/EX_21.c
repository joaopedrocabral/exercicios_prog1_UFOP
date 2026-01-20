#include <stdio.h>
#include <stdlib.h>

double converter_temp(double f){
    double c = (f-32) * (5.0/9.0);

    return c;
}

int main(){
    double f;

    printf("\nDIGITE OS GRAUS EM fahrenheit PARA CONVERTER EM celsius: ");
    scanf("%lf", &f);

    double c = converter_temp(f);

    printf("A TEMP. EM CELSIUS E: %.2f ºC", c);

    return 0;
}