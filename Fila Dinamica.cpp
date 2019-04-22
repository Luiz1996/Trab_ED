#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura da Lista Dinamica Duplamente Encadeada
typedef struct{
	int ra;
	char nome[30];
	//etc...
}aluno;

struct celula{
	aluno dados;
	celula* prox;
};

typedef struct {
	struct celula* primeiro;
	struct celula* ultimo;
}tipofila;

//funcoes para manipulacao da fila
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("\t\t\t\t\t\t     Fila Dinamica\nFuncoes Basicas:\n[1] Cria Fila Vazia\n[2] Fila Vazia?\n[3] Fila Cheia?\n[4] Libera Fila\n[5] Tamanho da Fila\n[6] Insere na Fila\n[7] Remove na Fila\n[8] Consulta na Fila\n[9] Imprime Fila\n\n\n[S/s]Sair\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

void cria_fila(tipofila *fila){
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	printf("Fila inicializada com sucesso!\n");
}

int fila_vazia(tipofila *fila){
	return (fila->primeiro == NULL);
}

void fila_cheia(){
	printf("A FILA NAO ESTA CHEIA.\n");
}

void libera_fila(tipofila *fila){
	if(!fila_vazia(fila)){
		celula *paux;
		while(fila->primeiro != NULL){
			paux = fila->primeiro;
			fila->primeiro = fila->primeiro->prox;
			free(paux);
		}
		free(fila->primeiro);
	}
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	printf("Fila destruida com sucesso!\n");
}

void tamanho_fila(tipofila *fila){
	celula *paux = fila->primeiro;
	int qtde = 0;
	while(paux != NULL){
		qtde++;
		paux = paux->prox;
	}
	printf("Nesta fila temos %d elemento(s).\n", qtde);
}

aluno obterDados(){
	aluno dados_novos;
	printf("RA..: ");
	scanf("%d", &dados_novos.ra);
	fflush(stdin);
	printf("Nome: ");
	scanf("%[^\n]s", &dados_novos.nome);
	system("cls");
	return dados_novos;
}

void insere(tipofila *fila){
	//declarando variaveis e preenchendo com novos dados
	celula* nova_celula = (celula*) malloc(sizeof(celula));
	nova_celula->dados = obterDados();
	nova_celula->prox = NULL;
		
	//inserindo nova celula no final da fila
	if(fila->ultimo == NULL){
		fila->primeiro = nova_celula;
		fila->ultimo = nova_celula;
	}else{
		fila->ultimo->prox = nova_celula;
		fila->ultimo = fila->ultimo->prox;
	}
	printf("Novos dados inseridos com Sucesso!\n");
}

void imprime_fila(tipofila *fila){
	if(fila_vazia(fila)){
		printf("FILA VAZIA.\n");
	}else{
		celula *paux = fila->primeiro;;
		int i = 1;
		
		while(paux != NULL){
			for(int cont = 0; cont < 120; cont++) printf("-");
			printf("(Elemento %d) : RA: %d - Nome: %s\n", i, paux->dados.ra, paux->dados.nome);
			paux = paux->prox;
			i++;
		}	
	}
}

void remove_fila(tipofila *fila){
	if(fila_vazia(fila)){
		printf("FILA VAZIA.\n");
	}else{
		celula *paux = fila->primeiro;
		if(fila->primeiro->prox == NULL){
			fila->primeiro = NULL;
			fila->ultimo = NULL;
		}else{
			fila->primeiro = fila->primeiro->prox;	
		}
		free(paux);
		printf("Os dados foram Removido com Sucesso!\n");
	}
}

void consulta_na_fila(tipofila *fila){
	if(fila_vazia(fila))
		printf("FILA VAZIA.\n");
	else
		printf("(Inicio Fila) -> (RA: %d - Nome: %s)\n", fila->primeiro->dados.ra, fila->primeiro->dados.nome);
}

//programa principal
int main(void){
	//variaveis
	tipofila fila;
	
	//controle de menu
	cria_fila(&fila);
	char opcao = showmenu(opcao); 
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				cria_fila(&fila);
				break;
			case '2':  
				fila_vazia(&fila) ? printf("FILA VAZIA.\n") : printf("A FILA NAO ESTA VAZIA.\n");
				break;
			case '3':
				fila_cheia();
				break;
			case '4':
				libera_fila(&fila);
				break;
			case '5':
				tamanho_fila(&fila);
				break;
			case '6':
				insere(&fila);
				break;
			case '7':
				remove_fila(&fila);
				break;
			case '8':
				consulta_na_fila(&fila);
				break;
			case '9':
				imprime_fila(&fila);
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
