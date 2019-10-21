#include "SO_utils.h"
#include <stdio.h>
#include <stdlib.h>

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

void valores_padroes(){
    printf("O programa se inicia com os respectivos valores iniciais\n");
}

void menu(){
    int opcao;
    valores_padroes();
    printf("Digite 1 para iniciar sem concorrência\n");
    printf("Digite 2 para iniciar com concorrência\n");
    printf("Digite 3 para personalizar as entradas\n");
    printf("Digite 4 para sair\n");

    scanf("%d",&opcao);
    switch (opcao)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        exit(0);
        break;
    default:
        printf("Valor não identificado, favor tentar novamente\n");
        break;
    }
}