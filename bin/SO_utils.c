#include "SO_utils.h"

void calcula_tempo(){
}

int verifica_primo(int numero){
    int count = numero / 2;
    int i;
    for (i = 2; i < count; i++){
        if ((numero % i) == 0)
            return 0;
    }
    return 1;    
}
