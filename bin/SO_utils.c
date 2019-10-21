#include <stdio.h>
#include <stdlib.h>
#include "SO_utils.h"

int** criaMatriz(unsigned int linha, unsigned int coluna, unsigned int semente) { // cria a matriz **testada**
	int m, n;
	int** matriz; //cria uma matriz
	srand(semente); // coloca um semente pr� definida
	matriz = (int**)malloc(sizeof(int*) * linha); // Um vetor de m ponteiros para inteiros
	if (matriz == NULL) { // verifica se ainda tem espa�o na memoria 
		printf("** Error: Memoria Insuficiente **");
		return (NULL);
	}
	for (m = 0; m < linha; m++) { // m vetores de n inteiros
		matriz[m] = (int*)malloc(sizeof(int*) * coluna);
		if (matriz[m] == NULL) { // verifica se ainda tem espa�o na memoria 
			printf("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}

	for (m = 0; m < linha; m++) { // percorre as linhas da matriz
		for (n = 0; n < coluna; n++) { // percorre as coluna da matriz 
			matriz[m][n] = (rand() % 30000); // gera um numero entre 0  a 29999 e coloca na posi��o Lin x Col
		}
	}

	return matriz;

}

int** destroiMatriz(unsigned int linha, unsigned int coluna, int** matriz) { // destroi a matriz **testada**
	int i, j; // variavel axiliar;
	if (matriz == NULL) { // verifica se a matriz n�o � nula
		return (NULL);
	}
	if (linha < 1 || coluna < 1) { // verifica parametros recebidos 
		printf("** Erro: Parametro invalido **\n");
		return (matriz);
	}
	for (i = 0; i < linha; i++) { // libera cada linha 
		free(matriz[i]);
	}
	free(matriz);
	return (matriz);
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
