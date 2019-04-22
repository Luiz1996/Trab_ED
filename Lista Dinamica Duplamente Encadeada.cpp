#include <stdio.h>
#include <stdlib.h>

//estrutura da Lista Dinamica Duplamente Encadeada
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

typedef struct {
	struct celula* primeiro;
	struct celula* ultimo;
}tipolista;

//funcoes que manipulam a lista criada
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("Funcoes Basicas: Lista Dinamica Duplamente Encadeada\n[1] Cria Lista Vazia\n[2] Lista Vazia?\n[3] Insere no Fim\n[4] Imprime Ordenado\n[5] Imprime Invertido\n\nFuncoes Solicitadas(Professor):\n[a] Inserir Ordenado\n[b] Inserir Inicio\n[c] Remove Final\n\n\n[S/s]Sair\n");
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
	lista->primeiro = (celula*) malloc(sizeof(celula));
	lista->ultimo = lista->primeiro;
	lista->primeiro->ant = NULL;
	lista->primeiro->prox = NULL;
	printf("Lista inicializada com sucesso!\n");
}

int lista_vazia(tipolista *lista){
	return (lista->primeiro == lista->ultimo);
}

void insere_fim(tipoitem novos_dados, tipolista *lista){
	lista->ultimo->prox = (celula*) malloc(sizeof(celula));
	lista->ultimo->prox->ant = lista->ultimo;
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item = novos_dados;
	lista->ultimo->prox = NULL;
}

void imprime_invertido(tipolista lista){
	if(lista_vazia(&lista)){
		printf("LISTA VAZIA.\n");
		return;
	}
	
	celula* aux;
	int i = 1;
	aux = lista.ultimo;
	while(aux != lista.primeiro){
		printf("(Elemento %d) : Chave: %d - Nome: %s\n", i, aux->item.chave, aux->item.nome);
		i++;
		aux = aux->ant;
	}	
}

void imprime_ord(tipolista lista){
	if(lista_vazia(&lista)){
		printf("LISTA VAZIA.\n");
		return;
	}
	
	celula* aux;
	int i = 1;
	aux = lista.primeiro->prox;
	while(aux != NULL){
		printf("(Elemento %d) : Chave: %d - Nome: %s\n", i, aux->item.chave, aux->item.nome);
		i++;
		aux = aux->prox;
	}
}

void insere_ordenado(tipolista *lista, tipoitem dados_novos){
	if(lista_vazia(lista)){ //se lista vazia insere normal, como se fosse no fim
		insere_fim(dados_novos, lista);
	}else{
		//ponteiro auxiliar
		celula *paux = lista->primeiro;
		celula *pins = (celula*) malloc(sizeof(celula));
		pins->item = dados_novos;
		
		//procurando posicao exata
		while(paux->prox != NULL && paux->prox->item.chave < dados_novos.chave)
			paux = paux->prox;
				
		//realizando a insercao
		if(paux->prox == NULL){//se for inserir na ultima posicao
			insere_fim(dados_novos, lista);		
		}else{//se for inserir entre duas celulas(meio)
			paux->prox->ant = pins;
			pins->prox = paux->prox;
			pins->ant = paux;
			paux->prox = pins;	
		}
	}
}

void insere_inicio(tipolista *lista, tipoitem dados_novos){
	if(lista_vazia(lista)){ //se lista vazia insere normal, como se fosse no fim
		insere_fim(dados_novos, lista);
	}else{
		//ponteiro auxiliar
		celula *pins = (celula*) malloc(sizeof(celula));
		pins->item = dados_novos;
		
		//realizando a insercao
		pins->prox = lista->primeiro->prox;
		pins->ant = lista->primeiro;
		lista->primeiro->prox = pins;
		pins->prox->ant = pins;
	}
}

void remove_final(tipolista *lista){
	if(lista_vazia(lista)){
		printf("LISTA VAZIA.\n");
		return;
	}else{
		//ponteiro auxiliar
		celula *paux = lista->ultimo;
		
		//removendo o ultimo
		lista->ultimo = lista->ultimo->ant;
		lista->ultimo->prox = NULL;
		free(paux);
	}
}

int main(void){
	tipolista lista;
	tipoitem dados_novos;
	
	//inicializando listas
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
				dados_novos = obterDados(dados_novos);
				insere_fim(dados_novos, &lista);
				break;
			case '4':
				imprime_ord(lista);
				break;
			case '5':
				imprime_invertido(lista);
				break;
			case 'a':
				dados_novos = obterDados(dados_novos);
				insere_ordenado(&lista, dados_novos);
				break;
			case 'b':
				dados_novos = obterDados(dados_novos);
				insere_inicio(&lista, dados_novos);
				break;
			case 'c':
				remove_final(&lista);
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
