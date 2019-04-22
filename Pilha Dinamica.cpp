#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estruturas e tipos
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
}tipopilha;

//funcoes para manipulacao da pilha
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("\t\t\t\t\t\t     Pilha Dinamica\nFuncoes Basicas:\n[1] Cria Pilha Vazia\n[2] Pilha Vazia?\n[3] Pilha Cheia?\n[4] Libera Pilha\n[5] Tamanho da Pilha\n[6] Insere na Pilha\n[7] Remove na Pilha\n[8] Consulta na Pilha\n[9] Imprime Pilha\n\nFuncoes Solicitadas(Professor):\n[a] Remove Elemento Especifico(usando apenas insere e remove)\n[b] Imprimir Elementos na Ordem de Entrada(Pilha Auxiliar)\n\n\n[S/s]Sair\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

void cria_pilha(tipopilha *pilha){
	pilha->primeiro = NULL;
	printf("Pilha Dinamica Criada Com Sucesso!\n");
}

int pilha_vazia(tipopilha *pilha){
		return (pilha->primeiro == NULL);
}


void pilha_cheia(){
	printf("A PILHA NAO ESTA CHEIA!\n");
}

void libera_pilha(tipopilha *pilha){
	if(!pilha_vazia(pilha)){
		celula *paux = pilha->primeiro;	
		while(pilha->primeiro != NULL){
			pilha->primeiro = pilha->primeiro->prox;
			free(paux);
			paux = pilha->primeiro;
		}
		free(pilha->primeiro);
		pilha->primeiro = NULL;
	}
	printf("A Pilha Dinamica foi destruida com sucesso!\n");
}

void tamanho_pilha(tipopilha *pilha){
	int qtde = NULL;
	if(!pilha_vazia(pilha)){
		celula *paux = pilha->primeiro;
		while(paux != NULL){
			qtde++;
			paux = paux->prox;
		}
	}
	printf("A Pilha Dinamica possui %d elemento(s).\n", qtde);
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

void insere(tipopilha *pilha, aluno dados, int imprime){
	//declarando variaveis e obtendo novos dados
	celula *paux = (celula*) malloc(sizeof(celula));
	paux->dados = dados;
	
	//inserindo nova celula
	if(pilha_vazia(pilha)){
		pilha->primeiro = paux;
		paux->prox = NULL;	
	}else{
		paux->prox = pilha->primeiro;
		pilha->primeiro = paux;
	}
	if(imprime)
		printf("Dados inseridos com Sucesso!\n");
}

void remove(tipopilha *pilha){
	if(pilha_vazia(pilha)){
		printf("PILHA VAZIA.\n");
	}else{
		celula *paux = pilha->primeiro;
		if(pilha->primeiro->prox == NULL){
			paux = pilha->primeiro;
			pilha->primeiro = NULL;	
		}else{
			paux = pilha->primeiro;
			pilha->primeiro = pilha->primeiro->prox;
		}
		free(paux);
	}
}

void consulta_na_pilha(tipopilha *pilha){
	if(pilha_vazia(pilha))
		printf("PILHA VAZIA.\n");
	else
		printf("(Topo da Pilha) -> (RA: %d - Nome: %s)\n", pilha->primeiro->dados.ra, pilha->primeiro->dados.nome);
}

void imprime_pilha(tipopilha *pilha){
	if(pilha_vazia(pilha)){
		printf("PILHA VAZIA.\n");
	}else{
		celula *paux = pilha->primeiro;;
		int i = 1;
		
		while(paux != NULL){
			for(int cont = 0; cont < 120; cont++) printf("-");
			printf("(Elemento %d) -> RA: %d - Nome: %s\n", i, paux->dados.ra, paux->dados.nome);
			paux = paux->prox;
			i++;
		}	
	}
}

void remove_especifico(tipopilha *pilha){
	//variaveis e estruturas auxiliares
	tipopilha pilha2;
	aluno dados = obterDados();
	celula *paux = pilha->primeiro;
	
	//copiando e desempilhando
	while(paux != NULL){
		if(dados.ra != paux->dados.ra){
			insere(&pilha2, paux->dados, NULL);
		}
		remove(pilha);
		paux = paux->prox;
	}
	
	//empilhando pilha atualizada
	paux = pilha2.primeiro;
	while(paux != NULL){
		insere(pilha, paux->dados, NULL);
		paux = paux->prox;
	}
	//imprimindo resultado
	imprime_pilha(pilha);
}

void imprime_ordem_entrada(tipopilha *pilha){
	//variaveis e estruturas auxiliares
	tipopilha pilha2;
	celula *paux = pilha->primeiro;
	
	//copiando e desempilhando
	pilha2.primeiro = NULL;
	while(paux != NULL){
		insere(&pilha2, paux->dados, NULL);
		paux = paux->prox;
	}
	
	//imprimindo
	if(pilha_vazia(&pilha2)){
		printf("PILHA VAZIA.\n");
	}else{
		paux = pilha2.primeiro;;
		int i = 1;

		while(paux != NULL){
			for(int cont = 0; cont < 120; cont++) printf("-");
			printf("(Elemento %d) -> RA: %d - Nome: %s\n", i, paux->dados.ra, paux->dados.nome);
			paux = paux->prox;
			i++;
		}	
	}
}

//programa principal
int main(void){
	//variaveis
	tipopilha pilha;
	aluno dados;
	
	//controle de menu
	cria_pilha(&pilha);
	char opcao = showmenu(opcao); 
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				cria_pilha(&pilha);
				break;
			case '2':  
				pilha_vazia(&pilha) ? printf("PILHA VAZIA.\n") : printf("A PILHA NAO ESTA VAZIA.\n");
				break;
			case '3':
				pilha_cheia();
				break;
			case '4':
				libera_pilha(&pilha);
				break;
			case '5':
				tamanho_pilha(&pilha);
				break;
			case '6':
				dados = obterDados();
				insere(&pilha, dados, 1);
				break;
			case '7':
				remove(&pilha);
				break;
			case '8':
				consulta_na_pilha(&pilha);
				break;
			case '9':
				imprime_pilha(&pilha);
				break;
			case 'a':
				remove_especifico(&pilha);
				break;
			case 'b':
				imprime_ordem_entrada(&pilha);
				break;
			
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
