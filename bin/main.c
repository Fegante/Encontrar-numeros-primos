#include "SO_utils.h"
#include "SO_utils.c"
#include <time.h>

int main()
{
    //Inicialização dos requisitos do programa
    clock_t tick[2];
    pthread_mutex_init(&lock_primo, NULL);
    pthread_mutex_init(&lock_macro_vet, NULL);
    double tempo_gasto;
    matriz = criaMatriz();
    int opcao, i;
    // preenche_inicio_macro(pos_macro);
    // imprime_macro_vet(pos_macro);

    // testa_percorre_macrobloco();
    while (opcao != 3)
    {

        opcao = menu();
        switch (opcao)
        {                      // Modularizar depois quando possível.
        case 1:                // SINGLE-CORE - **testada**
            tick[0] = clock(); //Inicio da contagem de tempo de execução.
            percorre_matriz(0, 0);
            tick[1] = clock(); // Fim do calculo, talvez seja interessante colocar depois dos joins que será quando as threads terminarão.
            tempo_gasto = ((tick[1] - tick[0]) / ((double)CLOCKS_PER_SEC / 1000));
            break;
        case 2:                // MULTI-CORE - INCOMPLETO - **não testada**
            tick[0] = clock(); //Inicio da contagem de tempo de execução.
            for (i = 0; i < TAM_MACROBLOCO; i++)
            {
                if (pthread_create(&threads[i], NULL, percorre_macrobloco, (void *)&pos_macro[i]) != 0)
                { // O ultimo parametro é o parametro pra função da thread.
                    printf("Houve um erro ao criar a thread %d\n", i);
                    break;
                }
            }
            tick[1] = clock(); // Fim do calculo de tempo
            break;
        default:
            printf("Saindo\n");
            break;
        }
        printf("\n\n");
        printf("############# RESULTADO ################\n");
        printf("#       Numero de primos %d            #\n", num_primos);
        printf("#    Tempo para contagem %.2lf ms      #\n", tempo_gasto);
        printf("########################################\n\n");
    }
    matriz = destroiMatriz(matriz);
    pthread_mutex_destroy(&lock_primo);
    pthread_mutex_destroy(&lock_macro_vet);
    return 0;
}