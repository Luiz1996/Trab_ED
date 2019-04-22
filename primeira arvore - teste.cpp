#include <stdio.h>
#include <stdlib.h>

struct registro{
	int chave;
};

struct no{
	struct registro reg;
	struct no* esq;
	struct no* dir;
};

int contaNos(struct no* p, int qtde){
	if(p != NULL){
		qtde = contaNos(p->esq, qtde);
		qtde++;
		qtde = contaNos(p->dir, qtde);
	}
	printf("\n%d \n", qtde);
	return qtde;
}

void in_ordem (no* T){
	if (T!=NULL){
		in_ordem (T->esq);
		printf("Item: %d",T->reg.chave);
		in_ordem (T->dir);
	}
}

int main(void){
	struct no* arv;
	
	arv = (struct no*) malloc(sizeof(struct no));
	
	arv->reg.chave = 2;  //2 na raiz
	arv->esq = (struct no*) malloc(sizeof(struct no));//declarando dois filhas da raiz 2
	arv->dir = (struct no*) malloc(sizeof(struct no));
	arv->esq->reg.chave = 1;//inserindo valor nas filhas
	arv->dir->reg.chave = 3;
	
	//colocando as folhas como NULL
	arv->esq->esq = (struct no*) malloc(sizeof(struct no));
	arv->esq->esq->reg.chave = 987654321;
	arv->esq->esq->esq = NULL;
	arv->esq->esq->dir = NULL;
	arv->esq->dir = NULL;
	arv->dir->esq = NULL;
	arv->dir->dir = (struct no*) malloc(sizeof(struct no));
	arv->dir->dir->reg.chave = 99999999;
	arv->dir->dir->dir = NULL;
	arv->dir->dir->esq = NULL;
	
	int n = 0;
	printf("Elementos da Folha: ");
	printf("\n\nA arvore tem %d no(s).", contaNos(arv, n));
	
}
