#include <stdio.h>
#include <stdlib.h>

typedef struct No { //cria��o de n�s / nodos
	int valor;
	struct No *proximo;
} No;

typedef struct  { //cria��o da estrutura da lista
	No *inicio, *fim; //ponteiros
	int tam;
} Lista;

void inserirInicio(Lista  *lista, int valor){
	//parametro o endere�o da lista, e o tipo de valor (Lista = estrutura, lista = ponteiro)
	No *novo = (No*)malloc(sizeof(No)); //comando para aloca��o de mem�ria
	novo->valor = valor; //(*novo).valor = valor
	
	if(lista->inicio == NULL){ //verifica sea lista est� vazia
		novo->proximo = NULL;
		lista->inicio = novo;
		lista->fim = novo;		
	}	
	else{ //A lista n�o est� vazia
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}
	lista->tam++;
}

void inserirFim(Lista *lista, int valor){
	No *novo =  (No*)malloc(sizeof(No));
	novo->valor = valor;
	novo->proximo = NULL; //nulo pois � o ultimo elemento
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
	}
	else{
		lista->fim->proximo = novo;
		lista->fim = novo;
	}
	lista->tam++;
}

void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	printf("Tamanho da  lista: %d", lista->tam);
	while(inicio != NULL){
		printf("%d ", inicio->valor);
		inicio = inicio->proximo;
	}
	printf("\n\n");
}

void remover(Lista *lista, int valor){
	No *inicio = lista->inicio;
	No * noARemover = NULL;
	
	if(inicio != NULL  && lista->inicio->valor == valor){
		noARemover = lista->inicio;
		lista->inicio = noARemover->proximo;
		if(lista->inicio == NULL){
			lista->fim  = NULL;
		} else { //remo��o no meio ou no final
			while(inicio != NULL && inicio->proximo != NULL){
				inicio = inicio->proximo;
			}
			if(inicio != NULL && inicio->proximo != NULL){
				noARemover = inicio->proximo;
				inicio->proximo= noARemover->proximo;
				if(inicio->proximo == NULL){
					lista->fim = inicio;
				}
			}
		}
	}
}


int main(void){
	struct Lista minhaLista;
	char op;
	int val;
	printf("Insira a opera��o desejada:");
	scanf("%s", &op);
	switch (op){
		case 1:
			printf("Insira o valor a ser inserido: ");
			scanf("%d", &val);
			inserirInicio(&minhaLista, val);
			break;
	}
}
