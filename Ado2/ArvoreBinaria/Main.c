#include<stdio.h>
#include<stdlib.h>


typedef struct no {
	struct no *esq;
	struct no *dir;
	int valor;
}no;



void inserirNo(no **raiz, int elemento) {

	if (*raiz == NULL)
	{
		no *aux = (no *)malloc(sizeof(no));
		aux->valor = elemento;
		aux->dir = aux->esq = NULL;
		*raiz = aux;
		printf("O elemento %d inserido....\n", elemento);
		return;
	}
	if (elemento < (*raiz)->valor)
	{
		inserirNo(&(*raiz)->esq, elemento);
		return;
	}
	if (elemento > (*raiz)->valor)
	{
		inserirNo(&(*raiz)->dir, elemento);
		return;
	}
	if (elemento == (*raiz)->valor)
	{
		printf("O elemento a ser inserido ja existe....\n");
	}
}

no *Filhos(no *sub_arvore) {
	if (sub_arvore == NULL)
	{
		return NULL;
	}
	else if (sub_arvore->esq == NULL)
	{
		return sub_arvore;
	}
	else
	{
		Filhos(sub_arvore->esq);
	}
}


void removerNo(no **raiz, int elemento) {
	
	if (elemento < (*raiz)->valor)
	{
		removerNo(&(*raiz)->esq, elemento);
		return;
	}
	if (elemento > (*raiz)->valor)
	{
		removerNo(&(*raiz)->dir, elemento);
		return;
	}
	else if ((*raiz)->esq != NULL && (*raiz)->dir != NULL)
	{
		no *aux = NULL;
		aux = Filhos((*raiz)->dir);
		(*raiz)->valor = aux->valor;
		removerNo(&(*raiz)->dir, (*raiz)->valor);
	}
	else
	{
		no *aux = (*raiz);
		if ((*raiz)->esq == NULL)
		{
			(*raiz) = (*raiz)->dir;
		}
		else
		{
			(*raiz) = (*raiz)->esq;
		}
		free(aux);
		printf("o elemento %d foi removido....\n", elemento);
	}

}

void buscaRecursiva(no **raiz, int elemento) {

	if (elemento < (*raiz)->valor)
	{
		buscaRecursiva(&(*raiz)->esq, elemento);
	}
	if (elemento > (*raiz)->valor)
	{
		buscaRecursiva(&(*raiz)->dir, elemento);
	}
	if (elemento == (*raiz)->valor)
	{
		printf("\no elemento %d foi encontrado...", elemento);
	}
	if (elemento != (*raiz)->valor)
	{
		printf("\no elemento %d não foi encontrado...", elemento);
	}
}

void preOrdem(no *raiz) {

	if (raiz == NULL)
	{
		return;
	}
	printf("%d ", raiz->valor);
	preOrdem(raiz->esq);
	preOrdem(raiz->dir);
}

void posOrdem(no *raiz) {

	if (raiz == NULL)
	{
		return;
	}
	posOrdem(raiz->esq);
	posOrdem(raiz->dir);
	printf("%d ", raiz->valor);
}

void inOrdem(no *raiz) {

	if (raiz == NULL)
	{
		return;
	}
	inOrdem(raiz->esq);
	printf("%d ", raiz->valor);
	inOrdem(raiz->dir);
}

int main() {

	no *raiz = NULL;

	inserirNo(&raiz, 5);
	inserirNo(&raiz, 7);
	inserirNo(&raiz, 10);
	inserirNo(&raiz, 4);
	removerNo(&raiz, 10);
	inserirNo(&raiz, 10);
	preOrdem(raiz);
	posOrdem(raiz);
	inOrdem(raiz);
	buscaRecursiva(&raiz, 4);
	buscaRecursiva(&raiz, 6);
	getchar();
	return 0;
}