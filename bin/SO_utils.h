#ifndef SO_UTILS_INCLUDED
#define SO_UTILS_INCLUDED

#define linha 10
#define coluna 10
#define seed 6415

int num_primos = 0;

/*
*
*/
void calcula_tempo();

/*Dado uma matriz imprime seus dados*/
void imprime_matriz(int** matriz);

/* i e j são valores inicias dos macroblocos.
Arrumar um nome melhor pra essa função.
*/
void percorre_matriz(int** matriz, unsigned int i, unsigned int j);

/*Preenche uma matriz AxB Com valores aleatorio entre 30000
* Inputs: Matriz
*/
int** cria_matriz(unsigned int semente);

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
int numero_de_primos(int** matriz, int i, int j)

int numero_de_primos(int matriz[], int i, int j);

void valores_padroes();

void menu();

#endif

