#include "SO_utils.h"

void calcula_tempo(){
}

int verifica_primo(int numero){
    int count = numero / 2;
    for (int i = 2; i < count; i++){
        if ((numero % i) == 0)
            return 0;
    }
    return 1;    
}

int numero_de_primos(int matriz[], int i, int j ){
    int aux;
    for ( int k = 0; k < (i+j); i++)
    {
        aux += verifica_primo(matriz[k]);
    }
    return aux;
}
