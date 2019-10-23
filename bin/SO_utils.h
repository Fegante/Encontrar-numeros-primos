#ifndef SO_UTILS_INCLUDED
#define SO_UTILS_INCLUDED

//Tamanho da matriz base
#define linha 1000
#define coluna 1000
#define seed 6415
#define macrobloco 3
#define MAX_VALOR_ALEATORIO 30000

int num_primos = 0;
int **matriz;

/*
*
*/
void calcula_tempo();

/* Verifica o tamanho dos macroblocos de acordo com a definição
daquela rodada de execução.
*/
void calcula_macrobloco ();

/*Dado uma matriz imprime seus dados*/
void imprime_matriz(int** matriz);

/* i e j são valores inicias dos macroblocos.
Arrumar um nome melhor pra essa função.
*/
void percorre_matriz(int** matriz, unsigned int i, unsigned int j);

/*Preenche uma matriz AxB Com valores aleatorio entre 30000
* Inputs: Matriz
*/
int** criaMatriz(unsigned int semente);

/*
*
*/
int** destroi_matriz(int** matriz);

/* Retorna
*  0 Caso numero não seja primo
*  1 Para o numero primo*/
int verifica_primo(int numero);

/*
*
*/
int numero_de_primos(int** matriz, int i, int j);

void valores_padroes();

void menu();

#endif

