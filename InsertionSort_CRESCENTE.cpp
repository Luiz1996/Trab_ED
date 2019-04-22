/*InsertionSort CRESCENTE*/
#include <stdio.h>
#define TAM_V 1000

void Insertion_Sort_CRESCENTE(int *v){
	int auxiliar, j;
	for (int i = 1; i < TAM_V; i++) {
		auxiliar = v[i];		
		for (j = (i - 1); (j >= 0) && (auxiliar < v[j]); j--) {
			v[j + 1] = v[j];
        }
		v[j + 1] = auxiliar;
	}
}

int main(void){
	int v[TAM_V] = {};

	/*Preenchendo vetor de forma desordenada*/
	for(int i = 0; i < TAM_V; i++){
		v[i] = TAM_V - i;
	}

	Insertion_Sort_CRESCENTE(v);

	/*Imprimindo ordenado*/
	for(int i = 0; i < TAM_V; i++){
		printf("%d ", v[i]);
	}
}
