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
	tipoitem item;
	celula *prox;
};

typedef struct{
	celula* primeiro;
}tipolista;

//funcoes basicas para manipulacao da lista circular
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("Funcoes Basicas: Lista Circular\n[1] Cria Lista C. Vazia\n[2] Lista C. Vazia?\n[3] Insere na Lista C.\n[4] Remove da Lista C.\n[5] Imprime Lista C.\n\nFuncoes Solicitadas(Professor):\n[a] Quantidade de Elementos\n[b] Copia Lista C.\n[c] Imprime Lista C. Copia\n\n[S/s]Sair\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

 celula obterDados(celula dados){
	fflush(stdin);
	printf("Insira a chave: ");
	scanf("%d", &dados.item.chave);
	fflush(stdin);
	printf("Insira o nome.: ");
	scanf("%[^\n]s", dados.item.nome);
	dados.prox = NULL;
	
	return (dados);
}

void listavazia(tipolista* lista){
	lista->primeiro = NULL;
}

int vazia(tipolista lista){
	return (lista.primeiro == NULL);
}

void insere(celula dados_novos, tipolista *lista){
	//ponteiros auxiliares
	celula *paux, *pins = (celula*) malloc(sizeof(celula));
	
	//atribuição dos dados
	pins->item.chave = dados_novos.item.chave;
	strcpy(pins->item.nome, dados_novos.item.nome);
	pins->prox = NULL;
	
	//realizando insercao dos novos dados
	if(lista->primeiro == NULL){
		lista->primeiro = pins;
		pins->prox = pins;
	}else{
		paux = lista->primeiro;
		while(paux->prox != lista->primeiro)
			paux = paux->prox;
			
		pins->prox = lista->primeiro;
		paux->prox = pins;
	}
}

int contaElementos(tipolista *lista, int imprime){
	int i = 1;
	if(lista->primeiro == NULL)
		printf("LISTA VAZIA.\n");
	else{
		celula *paux = lista->primeiro;
		while(paux->prox != lista->primeiro){
			i++;
			paux = paux->prox;
		}
		if(imprime)
			printf("Nesta Lista temos %d elemento(s).\n", i);
	}
	return i;
}

void imprime(tipolista *lista){
	celula *paux;
	int qtde = 1;
	
	//se a lista estiver vazia retorna
	if(vazia(*lista)){
		printf("LISTA VAZIA.\n");
		return;	
	}

	//realiza a impressao dos dados
	paux = lista->primeiro;
		while(paux->prox != lista->primeiro){
		for(int cont = 0; cont < 120; cont++) printf("-");
		printf("(Elemento %d) : Chave: %d - Nome: %s\n", qtde, paux->item.chave, paux->item.nome);
		paux = paux->prox;
		qtde++;
	}
}

void copiaLista(tipolista *lista, tipolista *lista_copia){
	celula *paux = lista->primeiro, *dados_novos;
	
	//verificando se a lista de origem esta vazia
	if(vazia(*lista)){
		printf("A lista de origem esta VAZIA.\n\t\t\t\t\t\tCOPIA INTERROMPIDA!\n");
		return;	
	}
	
	//inserindo os dados na lista_copia
	for(int j = 0; j < contaElementos(lista, NULL); j++){
		dados_novos = paux;
		paux = paux->prox;
		insere(*dados_novos, lista_copia);
	}
	printf("Lista copiada com EXITO!\n");
}

void removeFinal(tipolista *lista){
	celula *premove, *paux = lista->primeiro;
	
	//verificando se a lista de origem esta vazia
	if(vazia(*lista)){
		printf("LISTA VAZIA\n");
		return;	
	}else{ //se lista origem != vazia, entao copia
		if(lista->primeiro->prox == lista->primeiro){ //copia quando a lista origem tem apenas 1 elemento
			lista->primeiro = NULL;
			free(paux);
		}else{//copia quando a lista origem tem mais de 1 elemento
			for(int j = 0; j < (contaElementos(lista, NULL)-2); j++) /*subtrai dois, pois a funcao contaElementos já inicializa i = 1*/
				paux = paux->prox;									 /*e também não quero ir na ultima posicao e, sim, na penultima para realizar a remocao com sucesso*/
		
			premove = paux->prox;
			paux->prox = lista->primeiro;
			free(premove);	
		}
	}	
	printf("Elemento removido com SUCESSO.\n");
}

int main(void){
	tipolista lista, lista_copia;
	struct celula dados_novos;
	
	//inicializando listas
	listavazia(&lista);
	listavazia(&lista_copia);
	printf("Listas vazias criadas com sucesso.\n");
	
	char opcao = showmenu(opcao); 
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				listavazia(&lista);
				printf("Lista vazia criada com sucesso.\n");
				break;
			case '2': 
				vazia(lista) ? printf("LISTA VAZIA.\n") : printf("A LISTA NAO ESTA VAZIA.\n");
				break;
			case '3':
				dados_novos = obterDados(dados_novos);
				insere(dados_novos, &lista);
				break;
			case '4':
				removeFinal(&lista);
				break;
			case '5':
				imprime(&lista);
				break;
			case 'a':
				contaElementos(&lista, 1);
				break;
			case 'b':
				listavazia(&lista_copia);
				copiaLista(&lista, &lista_copia);
				break;
			case 'c':
				imprime(&lista_copia);
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
