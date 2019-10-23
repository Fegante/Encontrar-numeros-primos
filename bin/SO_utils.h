#ifndef SO_UTILS_INCLUDED
#define SO_UTILS_INCLUDED

//Tamanho da matriz base

#define LINHA 1000
#define COLUNA 1000
#define SEMENTE 6415
#define MACROBLOCO 3

#define MAX_VALOR_ALEATORIO 30000

int num_primos = 0;
int **matriz;

/* Verifica o tamanho dos macroblocos de acordo com a definição daquela rodada de execução.
*  Input:;
*  output:;
*/
void calcula_macrobloco ();

/* Dado uma matriz imprime seus dados;
*  Input: Matriz que deseja plotar;
*  Output: -;
*/
void imprime_matriz(int** matriz);

/* i e j são valores inicias dos macroblocos.Arrumar um nome melhor pra essa função.
*  Input:;
*  Output:;
*/
void percorre_matriz(int** matriz, unsigned int i, unsigned int j);

/* Cria, aloca e preenche uma matriz AxB Com valores aleatorio entre 30000, com o tamanho definidos pelas variaves globais LINHA e COLUNA;
*  Inputs: -;
*  Output: A matriz criada;
*/
int** criaMatriz();

/* Destroi a matriz alocada 
*  Inputs: Matriz que não ira mais utiliza;
*  Output: NULL;
*/
int** destroi_matriz(int** matriz);

/* Verifica se o Número é primo
*  Input: Número inteiro que deja verificar se é primo;
*  Output: Retorna 1 para se o número for um número primo ou retorna 0 para números para não primos; 
*/
int verifica_primo(int numero);

/* Número de números primos dentro de uma matriz;
*  Input: Matriz que deseja percorrer, numeros 
*/
int numero_de_primos(int** matriz, int i, int j);

void valores_padroes();

void menu();

#endif

