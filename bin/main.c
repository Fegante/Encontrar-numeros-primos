#include <stdlib.h>
#include <stdio.h>
#include "SO_utils.h"
#include "SO_utils.c"




int main(){
    matriz = criaMatriz();
    percorre_matriz(matriz,0,0);
    printf("%d\n",num_primos);
    return 0;
}