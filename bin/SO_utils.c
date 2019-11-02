#include <stdio.h>
#include <stdlib.h>
#include "SO_utils.h"
#include <math.h>

int **criaMatriz()
{ // cria a matriz **testada**
    int m, n;
    int **matriz;                                   //cria uma matriz
    srand(SEMENTE);                                 // coloca um semente pré definida
    matriz = (int **)malloc(sizeof(int *) * LINHA); // Um vetor de m ponteiros para inteiros
    if (matriz == NULL)
    { // verifica se ainda tem espaço na memoria
        printf("** Error: Memoria Insuficiente **");
        return (NULL);
    }
    for (m = 0; m < LINHA; m++)
    { // m vetores de n inteiros
        matriz[m] = (int *)malloc(sizeof(int *) * COLUNA);
        if (matriz[m] == NULL)
        { // verifica se ainda tem espaço na memoria
            printf("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
    }

    for (m = 0; m < LINHA; m++)
    { // percorre as linhas da matriz
        for (n = 0; n < COLUNA; n++)
        {                                                  // percorre as coluna da matriz
            matriz[m][n] = (rand() % MAX_VALOR_ALEATORIO); // gera um numero entre 0  a 29999 e coloca na posição Lin x Col
        }
    }

    return matriz;
}

void imprime_macro_vet(att_macrobloco *pos_macro)
{
    int i;
    for (i = 0; i < TAM_MACROBLOCO; i++)
    {
        printf("Macro bloco %d\n", i);
        printf("Lin: %d Col: %d\n", pos_macro[i].L_inicio, pos_macro[i].C_inicio);
    }
}

void preenche_inicio_macro(att_macrobloco *pos_macro)
{ //Parece certo, mas tem que testar mais
    int i, j, k = 0;
    for (j = 0; j < TAM_MACROBLOCO; j += C_MACRO)
    {
        for (i = 0; i < TAM_MACROBLOCO; i += L_MACRO)
        {
            pos_macro[k].L_inicio = j;
            pos_macro[k].C_inicio = i;
            k++;
        }
    }

    //return pos_macro;
}

int **destroiMatriz(int **matriz)
{             // destroi a matriz **testada**
    int i, j; // variavel axiliar;
    if (matriz == NULL)
    { // verifica se a matriz não é nula
        return (NULL);
    }
    if (LINHA < 1 || COLUNA < 1)
    { // verifica parametros recebidos
        printf("** Erro: Parametro invalido **\n");
        return (matriz);
    }
    for (i = 0; i < LINHA; i++)
    { // libera cada linha
        free(matriz[i]);
    }
    free(matriz);
    return (matriz);
}

void zera_vetor(int *macro_vet){
    int i;
    for (int i = 0; i < TAM_MACROBLOCO; ++i) {
        macro_vet[i]=0;
    }
}

void *calcula_com_threads(void *arg){
    int i;
    
    for (i = 0; i < TAM_MACROBLOCO; i++) {
        pthread_mutex_lock(&lock_macro_vet);
        if (macro_vet[i] == 0) {
            macro_vet[i]=1;
            pthread_mutex_unlock(&lock_macro_vet);
            percorre_macrobloco(&pos_macro[i]);
        }
        else{
            pthread_mutex_unlock(&lock_macro_vet);
        }
    }
}

void imprime_matriz(int **matriz)
{ // imprime a matriz **testada**
    int i, j;
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void *percorre_macrobloco(void *arg)
{
    int primo_bloco;
    int i, j;
    int eh_primo;
    int local_primo = 0;
    att_macrobloco *posicao = arg;
    for (i = posicao->L_inicio; i < posicao->L_inicio + L_MACRO; i++)
    {
        //printf("Entrou\n"); //APAGAR
        for (j = posicao->C_inicio; j < posicao->C_inicio + C_MACRO; j++)
        {
            // printf("Linha: %d \nColuna: %d \nValor: %d\n\n", i, j, matriz[i][j]);
            eh_primo = verifica_primo(matriz[i][j]);
            if (eh_primo)
            {
                printf("i = %d;j = %d;eh_primo = %d\n",i,j,local_primo);
                local_primo++;
            }
        }
    }
    pthread_mutex_lock(&lock_primo);
    num_primos += local_primo; // Região critica.
    pthread_mutex_unlock(&lock_primo);
}

void testa_percorre_macrobloco()
{
    int i;

    preenche_inicio_macro(pos_macro);
    imprime_macro_vet(pos_macro);

    for (i = 0; i < TAM_MACROBLOCO; i++)
    {
        percorre_macrobloco(&pos_macro[i]);
    }
    imprime_matriz(matriz);
}

void percorre_matriz(unsigned int i, unsigned int j)
{ // imprime a matriz **testada**
    int eh_primo;
    int k, l;
    int local_primo = 0;
    for (k = i; k < LINHA; k++)
    {
        for (l = j; l < COLUNA; l++)
        {
            eh_primo = verifica_primo(matriz[k][l]);
            if (eh_primo)
            {
                local_primo++;
            }
        }
    }
    
    pthread_mutex_lock(&lock_primo);
    num_primos += local_primo; // Região critica.
    pthread_mutex_unlock(&lock_primo);

}

int verifica_primo(int numero)
{ // imprime a matriz **testada**
    int count = sqrt(numero);
    if (numero == 1 || numero == 0)
    {
        return 0;
    }
    for (int i = 2; i < (count + 1); i++)
    {
        if ((numero % i) == 0)
        {
            printf("Não é primo: %d\n", numero);
            return 0;
        }
    }
    printf("É primo: %d\n", numero);
    return 1;
}

void valores_padroes()
{
    printf("O programa se inicia com os respectivos valores iniciais\n");
    printf("#########################\n");
    printf("# Linhas:\t %d\n", LINHA);
    printf("# Colunas:\t %d\n", COLUNA);
    printf("# Seed\t\t %d\n", SEMENTE);
    printf("# Linha Macroblocos\t %d\n", L_MACRO);
    printf("# Coluna Macroblocos\t %d\n", C_MACRO);
    printf("# Threads\t %d\n", NUM_THREAD);
    printf("#########################\n\n");
}

int menu()
{
    int opcao;
    valores_padroes();
    printf("Digite 1 para rodar sem concorrencia\n");
    printf("Digite 2 para iniciar com concorrencia\n");
    printf("Digite 3 para sair\n");

    scanf("%d", &opcao);
    return opcao;
}
