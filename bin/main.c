#include <stdlib.h>
#include <stdio.h>
#include "SO_utils.h"
#include "SO_utils.c"
#include <time.h>

int main(){
   
    clock_t tick[2];
    double tempo_gasto;
    matriz = criaMatriz();
    
    tick[0] = clock(); //Inicio da contagem de tempo de execução.

    percorre_matriz(matriz,0,0);
    tick[1] = clock();
    tempo_gasto = ((tick[1] - tick[0]) / ((double)CLOCKS_PER_SEC/1000));
    printf("Numero de primos %d\n",num_primos);
    printf("Tempo para contagem %.2lf ms\n",tempo_gasto);
    matriz = destroiMatriz(matriz);
    return 0;
}