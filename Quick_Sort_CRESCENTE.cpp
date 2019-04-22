//LUIZ FLÁvetorIO PEREIRA RA91706
#include <stdio.h>
#define tam 10000

int particiona(int vetor[], int inicio, int final){
	int esquerdo, direito, pivetoro, aux;
	esquerdo = inicio;
	direito = final;
	pivetoro = vetor[inicio];
	
	while(esquerdo < direito){
		while(vetor[esquerdo] <= pivetoro){
			esquerdo++;
		}
		while(vetor[direito] > pivetoro){
			direito--;
		}
		if(esquerdo < direito){
			aux = vetor[esquerdo];
			vetor[esquerdo] = vetor[direito];
			vetor[direito] = aux;
		}
	}
	vetor[inicio] = vetor[direito];
	vetor[direito] = pivetoro;
	
	return direito;
}

void quicksort(int *vetor, int inicio, int fim){
	int pivetoro;
	if(fim > inicio){
		pivetoro = particiona(vetor, inicio, fim);
		quicksort(vetor, inicio, pivetoro-1);
		quicksort(vetor, pivetoro+1, fim);
	}
}

int main(void){
	int vetor[tam] = {};
	
	//Pior Caso: vetoretor totalmente desordenado
	for(int i = 0; i < tam; i++) vetor[i] = (tam - i); 
	
	quicksort(vetor, 0, (tam - 1));
	
	printf("-----------------------------------------------------CRESCENTE----------------------------------------------------------");
	for(int i = 0; i < tam; i++) printf("%d ", vetor[i]);
	printf("\n-------------------------------------------------------FIM--------------------------------------------------------------");
}
