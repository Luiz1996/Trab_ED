int maior(no* raiz){
	while(raiz->dir != NULL)
		raiz = raiz->dir;
	return(raiz->reg.chave);
}

void remove(no* raiz, int dado){
	no* aux;
	if(raiz == NULL){
		printf ("Arvore Vazia!\n");
	}else{
		if(dado < raiz->reg.chave){
			remove(raiz->esq, dado);
		}else{
			if(dado > raiz->reg.chave)
				remove(raiz->dir, dado);
			else{
				if(raiz->dir == NULL){
					aux = raiz;
					raiz = raiz->esq;
					free(aux);
				}else{
					if(raiz->esq == NULL){
						raiz = raiz;
						raiz = raiz->dir;
						free(aux);
					}else{
						raiz->reg.chave = maior(raiz->esq);
						remove(raiz->esq, raiz->reg.chave);
					}
				}
			}
		}
	}
}