#include <stdio.h>
#include <stdlib.h>

#define inicializa "Arvore Binaria de Busca Inicializada Com Sucesso!"

//estrutura de dados
typedef struct{
	int chave;
}registro;

struct no{
	registro reg;
	no* esq;
	no* dir;
};

//funcoes para manipulacao da pilha
char showmenu(char opcao){
	for(int i = 0; i < 120; i++) printf("=");
	printf("\t\t\t\t\t     Arvore Binaria de Busca\nFuncoes Basicas:\n[1] Inicializa Arvore\n[2] Arvore Vazia?\n[3] Arvore Cheia?\n[4] Insere Arvore\n[5] Grau De Um Determinado No\n[6] Quantidade de Elementos na Arvore\n[7] Remove na Arvore\n[8] Consulta na Arvore\n[9] Imprime Arvore In-Ordem\n\nFuncoes Adicionais:\n[a] Imprime Arvore em Pre-Ordem\n[b] Imprime Arvore em Pos-Ordem\n\n\n[0/S/s]Sair\n");
	for(int i = 0; i < 120; i++) printf("=");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opcao);
	
	return opcao;
}

int arvore_vazia(no *raiz){
	if(raiz == NULL)
		return 1;
	return 0;
}

void arvore_cheia(){
	printf("A Arvore Nao Esta Cheia.\n");
}

int obterDados(int verifica){
	int novo_dado;
	if(verifica)
		printf("Digite o Novo Numero a Ser Inserido: ");
	else
		printf("Elemento a Ser Buscado: ");
	scanf("%d", &novo_dado);
	return novo_dado;
}
	
void imprime_in_ordem(no* raiz){
	if(!arvore_vazia(raiz)){
		imprime_in_ordem(raiz->esq);
		printf("%d ",raiz->reg.chave);
		imprime_in_ordem(raiz->dir);	
	}
}

void imprime_pre_ordem(no* raiz){
	if(!arvore_vazia(raiz)){
		printf("%d ",raiz->reg.chave);
		imprime_pre_ordem(raiz->esq);
		imprime_pre_ordem(raiz->dir);	
	}
}

void imprime_pos_ordem(no* raiz){
	if(!arvore_vazia(raiz)){
		imprime_pos_ordem(raiz->esq);
		imprime_pos_ordem(raiz->dir);
		printf("%d ",raiz->reg.chave);	
	}
}

no* insere(no* raiz, int dado){
	if (raiz == NULL){
		raiz = (no*) malloc(sizeof(no));
		raiz->reg.chave = dado;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}else
		if (dado < raiz->reg.chave)
			raiz->esq = insere(raiz->esq, dado);	
		else
			if (dado > raiz->reg.chave)
				raiz->dir = insere(raiz->dir, dado);	
			else
				raiz->reg.chave = dado;
}

int consulta_no(no* raiz, int dado, int imprime_grau){
	if(!arvore_vazia(raiz)){
		if(dado == raiz->reg.chave){
			if(imprime_grau){
				if(raiz->dir == NULL & raiz->esq == NULL){
					printf("O No Com Valor %d, Tem Grau 0!\n", dado);
				}else{
					if(raiz->dir != NULL & raiz->esq != NULL){
						printf("O No Com Valor %d, Tem Grau 2!\n", dado);
					}else{
						printf("O No Com Valor %d, Tem Grau 1!\n", dado);
					}
				}
			}
			return 1;
		}else{		
			if(dado < raiz->reg.chave){
				if(raiz->esq != NULL)
					consulta_no(raiz->esq, dado, imprime_grau);			
				else
					return 0;
			}else{
				if(dado > raiz->reg.chave){
					if(raiz->dir != NULL)
						consulta_no(raiz->dir, dado, imprime_grau);	
					else
						return 0;
				}		
			}	
		}	
	}
}

int contaNos(no* raiz, int qtde){
	if(raiz != NULL){
		qtde = contaNos(raiz->esq, qtde);
		qtde++;
		qtde = contaNos(raiz->dir, qtde);
	}
	return qtde;
}

int maior(no* raiz){
	while(raiz->dir != NULL)
		raiz = raiz->dir;
	return(raiz->reg.chave);
}

no* remove(no* raiz, int dado){
	no* aux;
	if(raiz == NULL){
		printf ("Elemento nao encontrado na arvore!\n");
	}else{
		if(dado < raiz->reg.chave){
			raiz = remove(raiz->esq, dado);
		}else{
			if(dado > raiz->reg.chave)
				raiz = remove(raiz->dir, dado);
			else{
				if(raiz->dir == NULL){
					aux = raiz;
					raiz = raiz->esq;
					free(aux);
				}else{
					if(raiz->esq == NULL){
						aux = raiz;
						raiz = raiz->dir;
						free(aux);
					}else{
						raiz->reg.chave = maior(raiz->esq);
						raiz = remove(raiz->esq, raiz->reg.chave);
					}
				}
			}
		}
	}
}

//programa principal
int main(void){
	//variaveis
	int qtde = 0, dado = 0, maior_valor = 0;
	no *raiz = NULL;
	
	//controle de menu
	printf("%s\n", inicializa);
	char opcao = showmenu(opcao); 
	while(opcao != 's' && opcao != 'S' && opcao != '0'){
		system("cls");
		switch (opcao){
			case '1':
				raiz = NULL;
				printf("%s\n", inicializa);
				break;
			case '2':  
				arvore_vazia(raiz) ? printf("Arvore Vazia.\n") : printf("A Arvore Nao Esta Vazia.\n");
				break;
			case '3':
				arvore_cheia();
				break;
			case '4':
				dado = obterDados(1);
				raiz = insere(raiz, dado);
				system("cls");
				printf("O Valor %d Foi Inserido Com Sucesso!\n", dado);
				break;
			case '5':
				dado = obterDados(0);
				system("cls");
				if(!consulta_no(raiz, dado, 1))
					printf("Dado Valor %d NAO Foi Encontrado!\n", dado);
				break;
			case '6':
				printf("A Arvore Possui %d Elemento(s).\n", contaNos(raiz, qtde));
				break;
			case '7':
				if(!arvore_vazia(raiz)){
					dado = obterDados(0);
					system("cls");
					raiz = remove(raiz, dado);
				}
				break;
			case '8':
				dado = obterDados(0);
				system("cls");
				if(consulta_no(raiz, dado, 0))
					printf("Dado Valor %d Foi Encontrado!\n", dado);
				else
					printf("Dado Valor %d NAO Foi Encontrado!\n", dado);
				break;
			case '9':
				if(arvore_vazia(raiz)){
					printf("Arvore Vazia!\n");
				}else{
					printf("Em Ordem: ");
					imprime_in_ordem(raiz);
					printf("\n");	
				}
				break;
			case 'a':
				if(arvore_vazia(raiz)){
					printf("Arvore Vazia!\n");
				}else{
					printf("Pre Ordem: ");
					imprime_pre_ordem(raiz);
					printf("\n");	
				}
				break;
			case 'b':
				if(arvore_vazia(raiz)){
					printf("Arvore Vazia!\n");
				}else{
					printf("Pos Ordem: ");
					imprime_pos_ordem(raiz);
					printf("\n");	
				}
				break;
			default :
				printf("Opcao invalida!\n");
				break;
		}
		opcao = showmenu(opcao);
	}
}
