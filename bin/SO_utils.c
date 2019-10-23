#include <stdio.h>
#include <stdlib.h>
#include "SO_utils.h"
#include <math.h>


int** criaMatriz(unsigned int semente) { // cria a matriz **testada**
	int m, n;
	int** matriz; //cria uma matriz
	srand(semente); // coloca um semente pré definida
	matriz = (int**)malloc(sizeof(int*) * linha); // Um vetor de m ponteiros para inteiros
	if (matriz == NULL) { // verifica se ainda tem espaço na memoria 
		printf("** Error: Memoria Insuficiente **");
		return (NULL);
	}
	for (m = 0; m < linha; m++) { // m vetores de n inteiros
		matriz[m] = (int*)malloc(sizeof(int*) * coluna);
		if (matriz[m] == NULL) { // verifica se ainda tem espaço na memoria 
			printf("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}

	for (m = 0; m < linha; m++) { // percorre as linhas da matriz
		for (n = 0; n < coluna; n++) { // percorre as coluna da matriz 
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

void imprime_matriz(int** matriz){ // imprime a matriz **testada**
    int i,j;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}



void calcula_macrobloco (){
    if (macrobloco > linha && macrobloco > coluna){
        printf("Não é possível gerar esse numero de macroblocos com a matriz atual\n");
        return;
    }
    /* Estou mexendo (Diego)
    int mac_linha,mac_coluna,espaco_mat;
    if (linha <= coluna){
        mac_linha = (linha + coluna) / macrobloco;
        espaco_mat = linha * coluna;
        mac_coluna = ((espaco_mat / macrobloco) / mac_linha);
    }
    else{
        mac_coluna = (linha + coluna) / macrobloco;
        espaco_mat = linha * coluna;
        mac_linha = ((espaco_mat / macrobloco) / mac_coluna);    
    }
    printf("mac_linha é %d\n",mac_linha);
    printf("mac_coluna é %d\n",mac_coluna);
    */
}

/*Está errada, não é pra percorrer até linha ou coluna
Deve percorrer até o final do macrobloco. Ainda vai ser definido qual macrobloco*/
void percorre_matriz(int** matriz, unsigned int i, unsigned int j) { // imprime a matriz **testada**
    int eh_primo;
    int k,l;
    for (k = i; k < linha; k++) {
        for (l = j; l < coluna; l++) {
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
}

void menu(){
    int opcao;
    valores_padroes();
    printf("Digite 1 para iniciar sem concorrÃªncia\n");
    printf("Digite 2 para iniciar com concorrÃªncia\n");
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
        printf("Valor nÃ£o identificado, favor tentar novamente\n");
        break;
    }
}
