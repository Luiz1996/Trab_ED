#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int chave;
	char nome[30];
	//etc...
}tipoitem;

struct celula{
	tipoitem item;
	struct celula* prox;
};

typedef struct{
	celula *primeiro;
	celula *ultimo;
} tipolista;

char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("Funcoes Basicas:\n[1] Cria Lista Vazia\n[2] Lista Vazia?\n[3] Insere no Final da Lista\n[4] Localiza na Lista\n[5] Remove da Lista(escolhe chave a ser apagada)\n[6] Imprime Lista\n\nExercicios Professor:\n[a] Insere Ordenado na Lista\n[b] Insere no Inicio da Lista\n[c] Remove no Final da Lista\n[d] Remove no Inicio da Lista\n\n[S/s]Sair\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

void filavazia(tipolista *lista){
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	printf("Lista vazia criada com sucesso.\n");
}

int vazia(tipolista lista){
	return (lista.primeiro == lista.ultimo);
}

celula *localiza(tipoitem dados, tipolista *lista){
	struct celula *paux;
	paux = lista->primeiro;
	int i = 1;
	
	system("cls");
	while((paux->prox != NULL)){
		if(paux->prox->item.chave == dados.chave){
			printf("O dado com chave: %d, esta na posicao %d.\n", dados.chave, i);
			return (paux);
		}
		paux = paux->prox;
		i++;
	}
	
	printf("Dado nao encontrado.\n");
	return (paux);
}

void retira(struct celula *p, tipolista *lista){
	struct celula *q;
	if(vazia(*lista) || p->prox == NULL){
		printf("Erro: Lista vazia ou chave inexistente.\n");
		return;
	}else{
		q = p->prox;
		p->prox = q->prox;
		if(p->prox == NULL)
			lista->ultimo = p;
	}	
	free(q);
	printf("Dados removidos com sucesso!\n");
}

void imprime(tipolista lista){
	struct celula *aux;
	int i = 1, verificador;

	aux = lista.primeiro->prox;
	while(aux != NULL){
		for(int cont = 0; cont < 120; cont++) printf("-");
		printf("(Elemento %d) : Chave: %d - Nome: %s\n", i, aux->item.chave, aux->item.nome);
		aux = aux->prox;
		i++;
	}
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

void insereFinal(tipoitem dados, tipolista *lista){
	lista->ultimo->prox = (celula*) malloc(sizeof(celula));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item.chave = dados.chave;
	strcpy(lista->ultimo->item.nome, dados.nome);
	lista->ultimo->prox = NULL;
	system("cls");
	printf("A chave: %d e nome: %s, foram inseridos com sucesso.\n", dados.chave, dados.nome);
}

void insereOrdenado(tipoitem dados, tipolista *lista){
	celula *paux, *novacelula = (celula*) malloc(sizeof(celula));
	paux = lista->primeiro;
	
	//atribuindo os dados na nova celula
	novacelula->item.chave = dados.chave;
	strcpy(novacelula->item.nome, dados.nome);
	novacelula->prox = NULL;
	
	//achando posicao correta para inserir
	while((paux->prox != NULL) && (paux->prox->item.chave < dados.chave)){
		paux = paux->prox;
	}
	
	//inserindo nova celula
	if(paux->prox == NULL){ //mesma coisa que insereFinal
		lista->ultimo->prox = novacelula;
		lista->ultimo = lista->ultimo->prox;
		lista->ultimo->prox = NULL;
	}else{ //insere no começo ou meio da lista
		novacelula->prox = paux->prox;
		paux->prox = novacelula;
	}
}

void insereInicio(tipoitem dados, tipolista *lista){
	celula *novacelula = (celula*) malloc(sizeof(celula));
	
	//atribuindo os dados na nova celula
	novacelula->item.chave = dados.chave;
	strcpy(novacelula->item.nome, dados.nome);
	novacelula->prox = NULL;
	
	//inserindo novos dados
	if(lista->primeiro->prox == NULL){
		lista->primeiro->prox = novacelula;
		lista->ultimo = novacelula;
	}else{
		novacelula->prox = lista->primeiro->prox;
		lista->primeiro->prox = novacelula;	
	}
}

void retiraFinal(tipolista *lista){
	celula *aux1, *aux2;
	
	aux1 = lista->primeiro;
	aux2 = lista->ultimo;
	
	while(aux1->prox != aux2)
		aux1 = aux1->prox;
		
	lista->ultimo = aux1;
	aux1->prox = NULL;
	free(aux2);
}

void retiraInicio(tipolista *lista){
	celula *paux;
	
	paux = lista->primeiro->prox;
	lista->primeiro->prox = paux->prox;
	free(paux);
}

int main(void){
	tipolista lista;
	tipoitem dados;
	struct celula *paux;
	
	filavazia(&lista);
	char opcao = showmenu(opcao);
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				filavazia(&lista);
				break;
			case '2':
				int verificador; 
				verificador = vazia(lista) ? printf("LISTA VAZIA.\n") : printf("A LISTA NAO ESTA VAZIA.\n");
				break;
			case '3':
				dados = obterDados(dados);
				insereFinal(dados, &lista);
				break;
			case '4':
				if(vazia(lista)){
					printf("LISTA VAZIA.\n");
					break;	
				}
				dados = obterDados(dados);
				paux = localiza(dados, &lista);
				break;
			case '5':
				if(vazia(lista)){
					printf("LISTA VAZIA.\n");
					break;	
				}
				dados = obterDados(dados);
				paux = localiza(dados, &lista);
				retira(paux, &lista);
				break;
			case '6':
				if(vazia(lista)){
					printf("LISTA VAZIA.\n");
					break;	
				}
				imprime(lista);
				break;
			case 'a':
				dados = obterDados(dados);
				insereOrdenado(dados, &lista);
				break;
			case 'b':
				dados = obterDados(dados);
				insereInicio(dados, &lista);
				break;
			case 'c':
				if(vazia(lista)){
					printf("LISTA VAZIA.\n");
					break;	
				}
				retiraFinal(&lista);
				break;
			case 'd':
				retiraInicio(&lista);
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
