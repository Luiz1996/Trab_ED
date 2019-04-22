#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TAD = Tipo Abstrato de Dados, Lista Encadeada Dinamica Circular
typedef struct{
	int chave;
	char nome[30];
	//etc...
}tipoitem;

struct celula{
	celula* ant;
	tipoitem item;
	celula* prox;
};

typedef struct{
	celula* primeiro;
}tipolista;

//funcoes para manipulacaod a estrutura
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("Funcoes Basicas: Lista Dinamica Duplamente Encadeada Circular\n[1] Cria Lista Vazia\n[2] Lista Vazia?\n[3] Insere no Fim\n[4] Imprime Ordenado\n[5] Imprime Invertido\n[6] Remove Final\n[7] Conta Elementos\n\nFuncoes Solicitadas(Professor):\n[a] Remove Inicio\n[b] Insere Inicio\n[c] Insere Ordenado\n\n[S/s]Sair\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

tipoitem obterDados(tipoitem dados){
	fflush(stdin);
	printf("Insira a chave: ");
	scanf("%d", &dados.chave);
	fflush(stdin);
	printf("Insira o nome.: ");
	scanf("%[^\n]s", dados.nome);
	
	return (dados);
}

void cria_lista(tipolista *lista){
	lista->primeiro = NULL;
	printf("Lista inicializada com sucesso!\n");
}

int lista_vazia(tipolista *lista){
	return (lista->primeiro == NULL);
}

void insere(tipolista *lista){
	celula *aux = (celula*) malloc(sizeof(celula));
	aux->item = obterDados(aux->item);
	if(lista_vazia(lista)){
		lista->primeiro = aux;
		aux->prox = aux;
		aux->ant = aux;
	}else{
		aux->prox = lista->primeiro;
		aux->ant = lista->primeiro->ant;
		aux->ant->prox = aux;
		aux->prox->ant = aux;
	}
}

int contaElementos(tipolista *lista, int imprime){
	int i = 1;
	if(lista->primeiro == NULL){
		printf("LISTA VAZIA.\n");
		return 0;
	}else{
		celula *paux = lista->primeiro;
		while(paux->prox != lista->primeiro){
			i++;
			paux = paux->prox;
		}
		if(imprime)
			printf("Nesta Lista temos %d elemento(s).\n", i);
		return i;
	}
}

void imprime_ordenado(tipolista *lista){
	//se a lista estiver vazia retorna
	if(lista_vazia(lista)){
		printf("LISTA VAZIA.\n");
		return;	
	}

	celula *paux;
	int qtde = 1;
	//realiza a impressao dos dados
	paux = lista->primeiro;					
	for(int j = 0; j < contaElementos(lista, NULL); j++){
		for(int cont = 0; cont < 120; cont++) printf("-");
		printf("(Elemento %d) : Chave: %d - Nome: %s\n", qtde, paux->item.chave, paux->item.nome);
		paux = paux->prox;
		qtde++;
	}
}

void imprime_invertido(tipolista *lista){
	//se a lista estiver vazia retorna
	if(lista_vazia(lista)){
		printf("LISTA VAZIA.\n");
		return;
	}
	
	celula* paux = lista->primeiro->ant;
	int i = 1;
	
	//realiza a impressao
	for(int j = 0; j < contaElementos(lista, NULL); j++){
		for(int cont = 0; cont < 120; cont++) printf("-");
		printf("(Elemento %d) : Chave: %d - Nome: %s\n", i, paux->item.chave, paux->item.nome);
		i++;
		paux = paux->ant;
	}
}

void remove_final(tipolista *lista){
	int verifica = contaElementos(lista, NULL);
	celula *aux = lista->primeiro;
	
	if(verifica <= 0) //em caso da lista vazia
		return;
	
	if(verifica == 1) //quando tem apenas 1 elemento
		lista->primeiro = NULL;
	
	
	if(verifica == 2){ //quando há dois elementos precisa corrigir os ponteiros do ultimo elemento da lista
		aux = lista->primeiro->ant;
		lista->primeiro->ant = lista->primeiro;
		lista->primeiro->prox = lista->primeiro;
	}
		
	if(verifica > 2){ //quando a lista possui varios elementos(caso nao trivial)
		aux = lista->primeiro->ant;
		lista->primeiro->ant = lista->primeiro->ant->ant;
		lista->primeiro->ant->prox = lista->primeiro;
	}
	
	free(aux);
	printf("Elemento removido com sucesso!\n");
}

void remove_inicio(tipolista *lista){
	int verifica = contaElementos(lista, NULL);
	celula *aux = lista->primeiro;
	
	if(verifica <= 0) //em caso da lista vazia
		return;
	
	if(verifica == 1) //quando tem apenas 1 elemento
		lista->primeiro = NULL;
		
	if(verifica == 2){ //quando há dois elementos precisa corrigir os ponteiros do ultimo elemento da lista
		lista->primeiro = aux->prox;
		lista->primeiro->ant = lista->primeiro;
		lista->primeiro->prox  = lista->primeiro;	
	}
		
	if(verifica > 2){ //quando a lista possui varios elementos(caso nao trivial)
		lista->primeiro = aux->prox;
		lista->primeiro->ant = aux->ant;
		aux->ant->prox = lista->primeiro;
	}
	free(aux);
	printf("Elemento removido com sucesso!\n");
}

void insere_inicio(tipolista *lista){
	celula *aux = (celula*) malloc(sizeof(celula));
	aux->item = obterDados(aux->item);
	
	if(lista_vazia(lista)){
		lista->primeiro = aux;
		aux->ant = aux;
		aux->prox = aux;
	}else{
		aux->prox = lista->primeiro;
		aux->ant = lista->primeiro->ant;
		lista->primeiro->ant->prox = aux;
		lista->primeiro->ant = aux;
		lista->primeiro = aux;
	}
}

void insere_ordenado(tipolista *lista){
	celula *pt = lista->primeiro;
	celula *aux = (celula*) malloc(sizeof(celula));
	aux->item = obterDados(aux->item);
	
	if(lista_vazia(lista)){//quando nao tem elementos
		lista->primeiro = aux;
		aux->ant = aux;
		aux->prox = aux;
		return;
	}else{
		if(aux->item.chave <= pt->item.chave){//insere inicio
			aux->prox = lista->primeiro;
			aux->ant = lista->primeiro->ant;
			lista->primeiro->ant->prox = aux;
			lista->primeiro->ant = aux;
			lista->primeiro = aux;
			return;
		}else{
			if(aux->item.chave >= lista->primeiro->ant->item.chave){//insere fim
				aux->prox = lista->primeiro;
				aux->ant = lista->primeiro->ant;
				aux->ant->prox = aux;
				aux->prox->ant = aux;
			}else{//insere meio
				while(pt->prox != lista->primeiro && pt->prox->item.chave < aux->item.chave)
					pt = pt->prox;	
				
				aux->prox = pt->prox;
				pt->prox->ant = aux;
				pt->prox = aux;
				aux->ant = pt;	
			}	
		} 
	}
}

//programa principal
int main(void){
	tipolista lista;
	
	//inicializando lista
	cria_lista(&lista);
	
	char opcao = showmenu(opcao); 
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				cria_lista(&lista);
				break;
			case '2': 
				lista_vazia(&lista) ? printf("LISTA VAZIA.\n") : printf("A LISTA NAO ESTA VAZIA.\n");
				break;
			case '3':
				insere(&lista);
				break;
			case '4':
				imprime_ordenado(&lista);
				break;
			case '5':
				imprime_invertido(&lista);
				break;
			case '6':
				remove_final(&lista);
				break;
			case '7':
				contaElementos(&lista, 1);
				break;
			case 'a':
				remove_inicio(&lista);
				break;
			case 'b':
				insere_inicio(&lista);
				break;
			case 'c':
				insere_ordenado(&lista);
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
