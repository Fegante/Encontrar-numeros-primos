#ifndef SO_UTILS_INCLUDED
#define SO_UTILS_INCLUDED
#include <pthread.h>

//Tamanho da matriz base

//Começo das definição das variáves globais.
#define LINHA 1000		//Define uma o número de linhas que sua matriz vai ter .
#define COLUNA 1000		//Define o número de colunas que sua matriz vai ter .
#define SEMENTE 6415	//Define uma semente para que o srand possa ser o sempre o mesmo nos testes.
#define MACROBLOCO 3	//Define o número de macroblocos que tera no programa.
#define NUM_THREAD 4 //Define o número de threads que iram ser criadas.

#define MAX_VALOR_ALEATORIO 30000 //Define que o srand só poderá gerar número de 0 a 30000.

int num_primos = 0;     //Define uma variável  de forma global para que todas as threads possa adicionar o numero de primos achados nos MicroBlocos
int **matriz;			//Define a matriz de forma global apra que todas as threads possam olhara ela
pthread_t threads[NUM_THREAD]; //Vetor de threader que serao executadas.
pthread_mutex_t lock;          //Mutex, Controle de região critica.
//Termino da definição das variáves globais.


/* Verifica o tamanho dos macroblocos de acordo com a definição daquela rodada de execução.
*  Threads so podem receber um parametro com argumento, nesse caso possívelmente deverá ser um struct
*  Input:;
*  output:;
*/
void* percorre_macrobloco (void* arg);

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
*  Input: Matriz que deseja percorrer, numeros ;
*  Output: Número de números primos que existe dentro da matriz passada;
*/
int numero_de_primos(int** matriz, int i, int j);

/* Mostra os valores inicias das principais variaveis do sistema.
*/
void valores_padroes();

/* Imprime todas as opções possiveis no momento em que é executado o programa.
*/
int menu();

#endif

