#include <stdio.h>
#include <stdlib.h>
#include "SO_utils.h"
#include <math.h>


int** criaMatriz() { // cria a matriz **testada**
	int m, n;
	int** matriz; //cria uma matriz
	srand(SEMENTE); // coloca um semente pré definida
	matriz = (int**)malloc(sizeof(int*) * LINHA); // Um vetor de m ponteiros para inteiros
	if (matriz == NULL) { // verifica se ainda tem espaço na memoria 
		printf("** Error: Memoria Insuficiente **");
		return (NULL);
	}
	for (m = 0; m < LINHA; m++) { // m vetores de n inteiros
		matriz[m] = (int*)malloc(sizeof(int*) * COLUNA);
		if (matriz[m] == NULL) { // verifica se ainda tem espaço na memoria 
			printf("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}

	for (m = 0; m < LINHA; m++) { // percorre as linhas da matriz
		for (n = 0; n < COLUNA; n++) { // percorre as coluna da matriz 
			matriz[m][n] = (rand() % MAX_VALOR_ALEATORIO); // gera um numero entre 0  a 29999 e coloca na posição Lin x Col
		}
	}

	return matriz;

}

int** destroiMatriz(int** matriz) { // destroi a matriz **testada**
	int i, j; // variavel axiliar;
	if (matriz == NULL) { // verifica se a matriz não é nula
		return (NULL);
	}
	if (LINHA < 1 || COLUNA < 1) { // verifica parametros recebidos 
		printf("** Erro: Parametro invalido **\n");
		return (matriz);
	}
	for (i = 0; i < LINHA; i++) { // libera cada linha 
		free(matriz[i]);
        
	}
	free(matriz);
	return (matriz);
}

void imprime_matriz(int** matriz){ // imprime a matriz **testada**
    int i,j;
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void* percorre_macrobloco (void* arg){
    int primo_bloco;
    if (MACROBLOCO > LINHA && MACROBLOCO > COLUNA){
        printf("Não é possível gerar esse numero de macroblocos com a matriz atual\n");
    }
    /* PEDAÇO QUE CALCULA TUDO
    */

    pthread_mutex_lock(&lock);
    num_primos = num_primos + primo_bloco; // Região critica.
    pthread_mutex_unlock(&lock);
}

/*Está errada, não é pra percorrer até linha ou coluna
Deve percorrer até o final do macrobloco. Ainda vai ser definido qual macrobloco*/
void percorre_matriz(int** matriz, unsigned int i, unsigned int j) { // imprime a matriz **testada**
    int eh_primo;
    int k,l;
    for (k = i; k < LINHA; k++) {
        for (l = j; l < COLUNA; l++) {
            eh_primo = verifica_primo(matriz[k][l]);
            if (eh_primo == 0){
            }
            else{
                num_primos++;
            }
        }
    }
}

int verifica_primo(int numero) { // imprime a matriz **testada**
    int count = sqrt(numero);
    for (int i = 2; i < (count + 1); i++) {
        if ((numero % i) == 0)
            return 0;
    }
    return 1;    
}

void valores_padroes(){
    printf("O programa se inicia com os respectivos valores iniciais\n");
    printf("#########################\n");
    printf("# Linhas:\t %d\n",LINHA);
    printf("# Colunas:\t %d\n",COLUNA);
    printf("# Seed\t\t %d\n",SEMENTE);
    printf("# Macroblocos\t %d\n",MACROBLOCO);
    printf("# Threads\t %d\n",NUM_THREAD);
    printf("#########################\n\n");
}

int menu(){
    int opcao;
    valores_padroes();
    printf("Digite 1 para roda sem concorrencia\n");
    printf("Digite 2 para iniciar com concorrencia\n");
    printf("Digite 3 para sair\n");

    scanf("%d",&opcao);
    return opcao;
    }
