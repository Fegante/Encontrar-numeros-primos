#ifndef SO_UTILS_INCLUDED
#define SO_UTILS_INCLUDED


/*
*
*/
void calcula_tempo();

/*Preenche uma matriz AxB Com valores aleatorio entre 30000
* Inputs: Matriz
*/
void cria_matriz( int i,unsi int j, unsigned int semente)

/*
*
*/
void destroi_matriz(int linha, int coluna, int** matriz)

/* Retorna
*  0 Caso numero não seja primo
*  1 Para o numero primo
*/
int verifica_primo(int numero)

/*
*
*/
int numero_de_primos(int** matriz, int i, int j)

int numero_de_primos(int matriz[], int i, int j);

void valores_padroes();

void menu();

#endif

