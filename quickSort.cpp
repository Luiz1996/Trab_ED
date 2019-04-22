#include <stdio.h>
#define tam 6

int particiona(int V[], int inicio, int final){
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = V[inicio];
	
	while(esq < dir){
		while(V[esq] <= pivo){
			esq++;
		}
	
		while(V[dir] > pivo){
			dir--;
		}
		
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
		
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	
	return dir;
}

void quicksort(int *V, int inicio, int fim){
	int pivo;
	
	if(fim > inicio){
		pivo = particiona(V, inicio, fim);
		quicksort(V, inicio, pivo-1);
		quicksort(V, pivo+1, fim);
		
		
	}
}

int main(void){
	int V[tam] = {0,0,0,0,0,0};
	
	quicksort(V, 0, (tam - 1));
	
	printf("-----------------------------------------------------ORDENADO-----------------------------------------------------------");
	for(int i = 0; i < tam; i++) printf("%d ", V[i]);
	printf("\n-------------------------------------------------------FIM--------------------------------------------------------------");
}
