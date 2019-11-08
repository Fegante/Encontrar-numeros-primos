#ifndef SO_UTILS_INCLUDED
#define SO_UTILS_INCLUDED
#include <pthread.h>

//Tamanho da matriz base

//Come�o das defini��o das vari�ves globais.
#define LINHA 10000 											  //Define uma o n�mero de linhas que sua matriz vai ter .
#define COLUNA 20000											  //Define o n�mero de colunas que sua matriz vai ter .
#define SEMENTE 6415										  //Define uma semente para que o srand possa ser o sempre o mesmo nos testes.
#define L_MACRO 100											  //Define o n�mero de macroblocos que tera no programa.
#define C_MACRO 10											  //Define o n�mero de macroblocos que tera no programa.
#define NUM_THREAD 100										  //Define o n�mero de threads que iram ser criadas.
#define TAM_MACROBLOCO (LINHA * COLUNA) / (L_MACRO * C_MACRO) // Calcula numero de macroblocos
#define MAX_VALOR_ALEATORIO 4								  //Define que o srand s� poder� gerar n�mero de 0 a 30000.

struct att_macrobloco
{ // Estrutura necess�ria para enviar o inicio dos macroblocos para as threads.
	int L_inicio;
	int C_inicio;
};
typedef struct att_macrobloco att_macrobloco;

int num_primos ;			//Define uma vari�vel  de forma global para que todas as threads possa adicionar o numero de primos achados nos MicroBlocos
int** matriz;					//Define a matriz de forma global apra que todas as threads possam olhara ela
int macro_vet[TAM_MACROBLOCO];  //Controle dos macroblocos que est�o sendo utilizados.
pthread_t threads[NUM_THREAD];  //Vetor de threader que serao executadas.
pthread_mutex_t lock_primo;		//Mutex, Controle de regi�o critica.
pthread_mutex_t lock_macro_vet; //Muter para o vetor de macroblocos.
att_macrobloco pos_macro[TAM_MACROBLOCO];
//Termino da defini��o das vari�ves globais.

//De acordo com os dados de entrada verifica se o numero de macroblocos � certinho.
void verif_viabilidade_macrobloco();

void zera_vetor(int* macro_vet);//N�O FOI TESTADO AINDA

void* calcula_com_threads(void* arg); //N�O FOI TESTADO AINDA

//Preenche o vetor que dita as posi��es de inicio de cada macrobloco. PRECISAR TESTAR.
void preenche_inicio_macro(att_macrobloco* pos_macro);

/*Imprime vetor de macroblocos para teste*/
void imprime_macro_vet(att_macrobloco* pos_macro);

/* Verifica o tamanho dos macroblocos de acordo com a defini��o daquela rodada de execu��o.
*  Threads so podem receber um parametro com argumento, nesse caso poss�velmente dever� ser um struct
*  Input:;
*  output:;
*/
void* percorre_macrobloco(void* arg);

/* Dado uma matriz imprime seus dados;
*  Input: Matriz que deseja plotar;
*  Output: -;
*/
void imprime_matriz(int** matriz);

/* i e j s�o valores inicias dos macroblocos.Arrumar um nome melhor pra essa fun��o.
*  Input:;
*  Output:;
*/
void percorre_matriz(unsigned int i, unsigned int j);

/* Cria, aloca e preenche uma matriz AxB Com valores aleatorio entre 30000, com o tamanho definidos pelas variaves globais LINHA e COLUNA;
*  Inputs: -;
*  Output: A matriz criada;
*/
int** criaMatriz();

/* Destroi a matriz alocada
*  Inputs: Matriz que n�o ira mais utiliza;
*  Output: NULL;
*/
int** destroi_matriz(int** matriz);

/* Verifica se o N�mero � primo
*  Input: N�mero inteiro que deja verificar se � primo;
*  Output: Retorna 1 para se o n�mero for um n�mero primo ou retorna 0 para n�meros para n�o primos;
*/
int verifica_primo(int numero);

/* N�mero de n�meros primos dentro de uma matriz;
*  Input: Matriz que deseja percorrer, numeros ;
*  Output: N�mero de n�meros primos que existe dentro da matriz passada;
*/
int numero_de_primos(int** matriz, int i, int j);

/* Mostra os valores inicias das principais variaveis do sistema.
*/
void valores_padroes();

/* Imprime todas as op��es possiveis no momento em que � executado o programa.
*/
int menu();

void testa_percorre_macrobloco();

#endif
