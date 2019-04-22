/*InsertionSort DECRESCENTE*/
#include <stdio.h>
#define TAM_V 100000

void Insertion_Sort_DECRESCENTE(int *v){
	int auxiliar, j;
	for (int i = 1; i < TAM_V; i++) {
		auxiliar = v[i];		
		for (j = (i - 1); (j >= 0) && (auxiliar > v[j]); j--) {
			v[j + 1] = v[j];
        }
		v[j + 1] = auxiliar;
	}
}

int main(void){
	int v[TAM_V];

	/*Preenchendo vetor de forma ordenada*/
	for(int i = 0; i < TAM_V; i++){
		v[i] = i + 1;
	}

	Insertion_Sort_DECRESCENTE(v);

	/*Imprimindo ordenado*/
	for(int i = 0; i < TAM_V; i++){
		printf("%d ", v[i]);
	}
}