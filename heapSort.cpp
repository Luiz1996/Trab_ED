#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 6

//menu inicial
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("\t\t\t\t\t\t    *HEAP SORT*\n                                                   -------------\n[1] Carregar Vetor.\n[2] HeapSort.\n[3] Reinicia Vetor. \n[4] Imprime Vetor.\n\n\n[S/s/0]Sair.\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

//funcao que carrega o vetor com valores > 0
void carregaV(int V[]){
	int novo_valor = 1;//valor simbolico para entrar no while
	while(novo_valor > 0){
		//cai nesse caso quando não há posicao do vetor com valor zero, deste modo ele entende que todo vetor está cheio!
		if(V[TAM_MAX -1] != 0){
			system("cls");
			printf("\t\t\t\t\tA insercao de dados FALHOU!!!\n\n\t\t\t\t\t    MOTIVO: Vetor Cheio!\n\n \t\t\t\t\t\t E R R O R\n");
			return;	
		}
		printf("======================================================== CARREGA =======================================================");
	
		//receber dado do usuario
		printf("Para SAIR insira um valor < 1.\nInsira um valor (>0): ");
		scanf("%d", &novo_valor);
		system("cls");
		
		//se inserir valor menor ou igual a zero apresenta erro e volta ao menu inicial
		if(novo_valor <= 0){
			printf("Finalizado a insercao de dados!\n");
			return;
		}
		
		/*percorre vetor até achar uma posicao com valor zero, quando achar ele insere. Zero é atruido a todas as posicoes na declaracao do vetor, portanto, quando ele 
		encontra esse valor ele sabe que ali está disponivel para insercoes de dados*/
		for(int i = 0; i < TAM_MAX; i++){
			if(V[i] == 0){
				V[i] = novo_valor;
				printf("O valor %d foi inserido com sucesso!\n", novo_valor);
				if(i == TAM_MAX - 1){
					printf("\nVetor totalmente carregado!\n");
					return;
				}
				break;
			}
		}
	}
}

//funcao que imprime todos valores do vetor original V[]
void imprimeV(int *V){
	printf("======================================================== IMPRIME =======================================================");
	for(int i = 0; i < TAM_MAX; i++)
		printf("V[%d] = %d.\n", i, V[i]);
}

//funcao para zerar todos valores do vetor original V[]
void reiniciaVetor(int V[]){
	for(int i = 0; i < TAM_MAX; i++)
		V[i] = 0;
	
	printf("Vetor reiniciado com sucesso!\n");
}

void maxheap(int *V, int tam, int i){
	int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
	
	if(left < tam && V[left] > V[largest]){
		largest = left;
	}
	
	if(right < tam && V[right] > V[largest]){
		largest = right;
	}
	
	if(largest != i){
		int aux = V[i];
		V[i] = V[largest];
		V[largest] = aux;
		maxheap(V, tam, largest);
	}
}

void heapSort(int *V, int tam){
	for(int i = (TAM_MAX/2) - 1; i >= 0; i-- ){
		maxheap(V, tam, i);
	}
	
	for(int i = tam - 1; i >= 0; i--){
		int aux = V[0];
		V[0] = V[i];
		V[i] = aux;
		maxheap(V, i, 0);
	}
	
	printf("Vetor ordenado com sucesso!\n");
}

//programa principal
int main(void){
	int V[TAM_MAX] = {6,5,4,3,2,1};
	
	char opcao = showmenu(opcao); 
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				carregaV(V);
				break;
			case '2':  
				if(V[TAM_MAX -1] != 0)
					heapSort(V, TAM_MAX);
				else
					printf("Vetor nao foi totalmente preenchido!\n");
				break;
			case '3':
				reiniciaVetor(V);
				break;
			case '4':
				imprimeV(V);
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
