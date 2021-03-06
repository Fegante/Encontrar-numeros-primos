#include "SO_utils.h"
//#include "SO_utils.c"
#include <time.h>

int main()
{
	//Inicializa��o dos requisitos do programa
	clock_t tick[2];
	pthread_mutex_init(&lock_primo, NULL);
	pthread_mutex_init(&lock_macro_vet, NULL);
	double tempo_gasto;
	matriz = criaMatriz();
	int opcao=0, i;
	//printf("Tam Macro: %d\n",TAM_MACROBLOCO);
	//verif_viabilidade_macrobloco();
	preenche_inicio_macro(pos_macro);
	//imprime_matriz(matriz);
	// preenche_inicio_macro(pos_macro);
	// imprime_macro_vet(pos_macro);

	// testa_percorre_macrobloco();
	while (opcao != 3)
	{
		opcao = menu();
		switch (opcao)
		{                      // Modularizar depois quando poss�vel.
		case 1:                // SINGLE-CORE - **testada**
			tick[0] = clock(); //Inicio da contagem de tempo de execu��o.
			percorre_matriz(0, 0);
			tick[1] = clock(); // Fim do calculo, talvez seja interessante colocar depois dos joins que ser� quando as threads terminar�o.
			tempo_gasto = ((tick[1] - tick[0]) / ((double)CLOCKS_PER_SEC / 1000));
			break;
		case 2:                // MULTI-CORE - INCOMPLETO - **n�o testada**
			zera_vetor(macro_vet); //Prepara o vetor que sinaliza que os macroblocos n�o foram preenchidos.
			tick[0] = clock(); //Inicio da contagem de tempo de execu��o.
			for (i = 0; i < NUM_THREAD; i++) {
				if (pthread_create(&threads[i], NULL, calcula_com_threads, NULL) != 0) { // O ultimo parametro � o parametro pra fun��o da thread.
					printf("Houve um erro ao criar a thread %d\n", i);
				}
			}
			tick[1] = clock(); // Fim do calculo de tempo
			tempo_gasto = ((tick[1] - tick[0]) / ((double)CLOCKS_PER_SEC / 1000));
			for (i = 0; i < NUM_THREAD; i++) {
				pthread_join(threads[i], NULL);
			}
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
		num_primos = 0;
		tempo_gasto = 0;
	}
	matriz = destroiMatriz(matriz);
	pthread_mutex_destroy(&lock_primo);
	pthread_mutex_destroy(&lock_macro_vet);
	return 0;
}
