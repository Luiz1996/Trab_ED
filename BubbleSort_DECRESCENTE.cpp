/*BubbleSort ordenando em ordem DECRESCENTE*/
#include <stdio.h>
#define TAM_V 100000

void Bubble_Sort_DECRESCENTE(int *v){
	int auxiliar;
	for(int i = 1; i < TAM_V; i++){
		for(int j = 0; j < TAM_V - 1; j++){
			if (v[j] < v[j + 1]) {
                auxiliar = v[j];
                v[j] = v[j + 1];
                v[j + 1] = auxiliar;
            }
		}
	}
}

int main(void){
	int v[TAM_V];

	/*Preenchendo vetor de forma desordenada*/
	for(int i = 0; i <= TAM_V; i++){
		v[i] = i + 1;
	}

	/*Ordenando*/
	Bubble_Sort_DECRESCENTE(v);

	/*Imprimindo ordenado*/
	for(int i = 0; i < TAM_V; i++){
		printf("%d ", v[i]);
	}
}