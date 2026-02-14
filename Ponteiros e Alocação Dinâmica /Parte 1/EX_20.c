#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5;
    int *v = malloc(n * sizeof(int));

    printf("%lu\n", sizeof(v));
    printf("%lu\n", sizeof(*v));

    free(v);
    return 0;
}