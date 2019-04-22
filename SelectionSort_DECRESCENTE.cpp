/*SelectionSort ordenando em ordem DECRESCENTE*/
#include <stdio.h>
#define TAM_V 100000

void Selection_Sort_DECRESCENTE(int *v){
	int min, auxiliar;
  	for (int i = 0; i < (TAM_V-1); i++){
     	min = i;
     	for (int j = (i+1); j < TAM_V; j++) {
       		if(v[j] > v[min]) 
         		min = j;
     	}
     	if (v[i] != v[min]) {
       		auxiliar = v[i];
       		v[i] = v[min];
       		v[min] = auxiliar;
     	}
  	}
}

int main(void){
	int v[TAM_V];

	/*Preenchendo vetor de forma desordenada*/
	for(int i = 0; i < TAM_V; i++){
		v[i] = i + 1;
	}

	/*Ordenando*/
	Selection_Sort_DECRESCENTE(v);

	/*Imprimindo ordenado*/
	for(int i = 0; i < TAM_V; i++){
		printf("%d ", v[i]);
	}
}