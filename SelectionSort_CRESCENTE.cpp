/*SelectionSort ordenando em ordem CRESCENTE*/
#include <stdio.h>
#define TAM_V 10000

void Selection_Sort_CRESCENTE(int *v){
	int min, auxiliar;
  	for (int i = 0; i < (TAM_V-1); i++){
     	min = i;
     	for (int j = (i+1); j < TAM_V; j++) {
       		if(v[j] < v[min]) 
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
		v[i] = TAM_V - i;
	}

	/*Ordenando*/
	Selection_Sort_CRESCENTE(v);

	/*Imprimindo ordenado*/
	for(int i = 0; i < TAM_V; i++){
		printf("%d ", v[i]);
	}
}
